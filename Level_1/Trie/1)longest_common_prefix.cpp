Solution 1-:
Steps-:
1)Compare every charcter of string 1 with all other string by charcter one by one.

Code-: Time->O(M*N)  1st loop is -> M is the len of string 1 & 
                     2nd loop is -> N is the no. of strings for which we are comparing.
 string ans="";
      
       for(int i=0;i<arr[0].size();i++)
       {
           char ch=arr[0][i];
           bool match=true;
           for(int j=1;j<N;j++)
           {
              // not match
              if(i>=arr[j].size() || ch!=arr[j][i])
              {
                  match=false;
                  break;
              }
           }
           if(match==true)
           ans.push_back(ch);
           else
           break;
       }
       return (ans.size()==0)?"-1":ans;


Solution 2-:
Steps-:

1) TrieNode Class:
TrieNode represents a node in the trie data structure.
1.1 -> It has an array of children, which are pointers to other TrieNode objects. The size of the array is 26, assuming we're dealing with
lowercase English letters.
1.2 -> isEnd is a boolean flag that indicates whether the node represents the end of a word.

2) Trie Class:
Trie represents the trie data structure itself.
It has a root node representing the root of the trie.

insert function:
Inserts a word into the trie.
It iterates through each character of the word and creates new nodes if necessary to represent the path of the word in the trie.


3) longestCommonPrefix function:

Finds the longest common prefix among the words inserted into the trie.
It iterates down the trie until it finds a node with more than one child or reaches the end of a word.
At each step, it appends the corresponding character to the prefix string.
If it finds a node with more than one child or reaches the end of a word, it stops the traversal, indicating the end of the common prefix.

Solution Class:
Solution class contains the function longestCommonPrefix, which uses the Trie data structure to find the longest common prefix among an 
array of strings.
It initializes a Trie object and inserts all strings from the input array into the trie using the insert method.
Then, it retrieves the longest common prefix using the longestCommonPrefix method of the Trie object.
In the provided input where the string is too large to display, the code seems to handle a large array of strings, searching for their longest common prefix using the Trie data structure. Since the output is "-1", it indicates that there is no common prefix among the provided strings.


Code-: 
Time ->Overall, the time complexity of the longestCommonPrefix function is O(N * K + M), where N is the number of strings, 
       K is the average length of a string, and M is the length of the longest common prefix.


class TrieNode
{
    public:
    TrieNode* children[26];
    bool isEnd;
    
    TrieNode()
    {
        for(int i=0;i<26;i++)
        {
            children[i]=false;
        }
        isEnd=false;
    }
};


class Trie
{
    public:
    TrieNode* root;
    
    Trie()
    {
        root=new TrieNode();
    }
    
    void insert(string word)
    {
        TrieNode* curr=root;
        for(auto ch:word)
        {
            int index=ch-'a';
            if(curr->children[index]==NULL)
            curr->children[index]=new TrieNode();
            
            curr=curr->children[index];
        }
        curr->isEnd=true;
    }
    
    string longestCommonPrefix()
    {
        TrieNode* curr=root;
        string prefix="";
        while(true)
        {
            int count=0;
            int index=-1;
            
            for(int i=0;i<26;i++)
            {
                if(curr->children[i]!=NULL)
                {
                    count++;
                    index=i;
                }
            }
            
            if(count!=1 || curr->isEnd==true)
            break;
            prefix.push_back(index+'a');
            curr=curr->children[index];
        }
        return prefix;
    }
    
};
class Solution{
  public:
    
    string longestCommonPrefix (string arr[], int N)
    {
      Trie trie;
      
      for(int i=0;i<N;i++)
      {
          trie.insert(arr[i]);
      }
      if(trie.longestCommonPrefix().size()==0) return "-1";
      return trie.longestCommonPrefix();
    }
};



Time ->
The time complexity of the provided longestCommonPrefix function implemented using a Trie data structure depends on the length of the longest 
common prefix among the strings and the number of strings in the input array.

1) Insertion into Trie:
Inserting each string into the Trie takes O(K) time, where K is the length of the string. Since there are N strings, the total time complexity
for insertion is O(N * K), where N is the number of strings and K is the average length of a string.
2)Finding Longest Common Prefix:
Traversing the Trie to find the longest common prefix involves traversing down the Trie until either a node with more than one child is 
encountered or a node marking the end of a word is reached.

*In the worst-case scenario, where all strings have the same common prefix, the traversal will go until the depth of the Trie, 
which is the length of the longest common prefix.

*Hence, the time complexity for finding the longest common prefix is O(M), where M is the length of the longest common prefix.

*Overall, the time complexity of the longestCommonPrefix function is O(N * K + M), where N is the number of strings, K is the average length 
of a string, and M is the length of the longest common prefix.
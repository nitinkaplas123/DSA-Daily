Solution 1-:
Steps-:
Approach
1. Character Counting:

The code uses a hashmap to count the frequency of each character in all words.
2. Efficient Counting:

It leverages an unordered_map for efficient character lookup and frequency updates.
3. Divisibility Check:

It iterates through the hashmap to check if the count of each character is divisible by the number of words.
If any character count isn't divisible, it's impossible to make all words equal.
4. Return Boolean Result:

The function returns true if all character counts are divisible, indicating equal distribution is possible, and false otherwise.
Time Complexity:

O(N), where N is the total number of characters in all words.
Iterating through words and characters takes O(N) time.
Hashmap operations have an average-case time complexity of O(1).
Space Complexity:

O(C), where C is the number of distinct characters in the input words.
The hashmap stores character counts, using space proportional to the number of distinct characters.



Code-: 
 bool makeEqual(vector<string>& words) {
        int n=words.size();
        if(n==1) return 1;
        unordered_map<char,int>m;
        for(int i=0;i<n;i++)
        {
            string str=words[i];
            for(int j=0;j<str.length();j++)
            {
                m[str[j]]++;
            }
        }

        for(auto x:m)
        {
            int freq=x.second;
            if(freq%n!=0) return false;
        }
        return true;
    }



Solution 2-:
Steps-:
1)Using count [26] array.


Code-: Time->O(N) Space->O(1)
bool makeEqual(vector<string>& words) {
        int n=words.size();
        
        int count[26]={0};
        for(int i=0;i<n;i++)
        {
            string str=words[i];
            for(int j=0;j<str.length();j++)
            {
                count[str[j]-'a']++;
            }
        }

        for(int i=0;i<26;i++)
        {
            if(count[i]%n!=0) return false;
        }
        return true;
}
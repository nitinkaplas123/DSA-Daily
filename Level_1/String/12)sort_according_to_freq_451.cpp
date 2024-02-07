Solution 1-:
Steps-:
1)First we store all freq and value in map.
2)Then put in pair of vector.
3)sort the vector using comp function according to second value.
4)Now print all the char into ans string according to frequency.

Code-: Time->Nlog(N)
static bool comp(pair<char,int>&a,pair<char,int>&b)
    {
        return (a.second>b.second);
    }

    string frequencySort(string s) {
        unordered_map<char,int>m;
        for(int i=0;i<s.length();i++)
        {
            m[s[i]]++;
        }
        
        vector<pair<char,int>>v;
        for(auto x:m)
        {
            v.push_back({x.first,x.second});
        }

        sort(v.begin(),v.end(),comp);

        string ans="";
        for(int i=0;i<v.size();i++)
        {
            char first=v[i].first;
            int second=v[i].second;
            while(second--)
            {
                ans+=first;
            }
        }
        return ans;
    }


Solution 2-:
Steps-:

1. Initialize Frequency Map and Find Maximum Frequency:
Create an unordered map m to store the frequency of each character.
Initialize a variable maxx to keep track of the maximum frequency encountered so far.
Iterate through the characters of the input string s.
For each character s[i], increment its frequency in the map m.
Update maxx to be the maximum of maxx and the frequency of the current character s[i].

2. Construct the Vector of Buckets:
Create a 2D vector v where each row represents a frequency bucket.
Iterate through the key-value pairs in the frequency map m.
For each character-frequency pair (ch, freq), push the character ch into the bucket 
corresponding to its frequency freq.

3.Construct the Sorted String:
Initialize an empty string ans to store the sorted string.
Iterate from maxx down to 1 (decreasing order of frequency).
For each frequency i, iterate through the characters in the bucket v[i].
Append i copies of each character to the string ans using the string(i, x) constructor, 
where x is the character.

4. Return the Sorted String:
Return the sorted string ans.

Code-: Time->O(N)
string frequencySort(string s) {
        unordered_map<char,int>m;
        int maxx=0;
        for(int i=0;i<s.length();i++)
        {
            m[s[i]]++;
            maxx=max(maxx,m[s[i]]);
        }
         
        vector<vector<char>>v(maxx+1);
        for(auto x:m)
        {
            char ch=x.first;
            int freq=x.second;
           
            v[freq].push_back(ch);
        }
        
        string ans="";
        for(int i=maxx;i>0;i--)
        {
            for(auto x:v[i])
            {
              ans+=string(i,x);
            }
        }
        return ans;
    }
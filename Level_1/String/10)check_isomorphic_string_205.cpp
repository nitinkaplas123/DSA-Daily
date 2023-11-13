Solution 1-:
Steps-:
1)Using 2 hashmap 


Code-:
bool isIsomorphic(string s, string t) {
        if(s.length()!=t.length()) return false;
        int n=s.length();
        unordered_map<char,char>m1;
        unordered_map<char,char>m2;

        for(int i=0;i<n;i++)
        {
            if(m1[s[i]] and m1[s[i]]!=t[i]) return false;
            if(m2[t[i]] and m2[t[i]]!=s[i]) return false;
            m1[s[i]]=t[i];
            m2[t[i]]=s[i];
        }
        return true;
    }
Solution 1-:
Steps-:
1)using 2 for loop

Code-: Time->O(N^2) Space->O(1)
int maxLengthBetweenEqualCharacters(string s) {
        int n=s.length();
        int ans=-1;
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(s[i]==s[j])
                ans=max(ans,j-i-1);
            }
        }
        return ans;
}



Solution 2-:
Steps-:
1)using hashmap

Code-: Time->O(N) Space->O(N)
int maxLengthBetweenEqualCharacters(string s) {
        int n=s.length();
        int ans=-1;
        unordered_map<char,int>m;
        for(int i=0;i<n;i++)
        {
           char ch=s[i];
           if(m.find(ch)!=m.end())
           ans=max(ans,i-m[ch]-1);
           else
           m.insert({ch,i});
        }
        return ans;
}



Solution 3-:
Steps-:
1)just replace hashmap with count array size 26

Code-: Time->O(N) Space->O(26)
int maxLengthBetweenEqualCharacters(string s) {
        int n=s.length();
        int ans=-1;
        vector<int>count(26,-1);
        for(int i=0;i<n;i++)
        {
           char ch=s[i];
           if(count[ch-'a']!=-1)
           ans=max(ans,i-count[ch-'a']-1);
           else
           count[ch-'a']=i;
        }
        return ans;
}
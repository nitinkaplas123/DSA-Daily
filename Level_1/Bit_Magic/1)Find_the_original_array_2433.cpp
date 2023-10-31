Solution 1-:
Steps-:
1)Just store the prev value in prev variable.
2)curr store in ans 

Code-:
vector<int> findArray(vector<int>& pref) {
        int n=pref.size();
        vector<int>v;
        int ans=pref[0];
        int prev=pref[0];
        v.push_back(pref[0]);

        for(int i=1;i<n;i++)
        {
          ans=prev^pref[i];
          v.push_back(ans);
          prev=prev^ans;
        }
        return v;
    }
// comp sort according to second value in pair 
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
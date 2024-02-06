Solution 1-:
Steps-:
1)make a hashmap where we store the freq.
2)now copy the value of map into pair of vector.
3)sort the vector according to freq.
4)now make use of hashset where we store the unique values if value is present in set 
  ans++ and freq-=1;


Code-:
bool static comp(pair<int,int>&a,pair<int,int>&b)
{
        return (a.second<b.second);
}

int minDeletions(string s) {
        int n=s.length();
        unordered_map<int,int>m;

        for(int i=0;i<n;i++)
        {
            m[s[i]]++;
        }

        vector<pair<int,int>>v;
        for(auto x:m)
        {
            v.push_back({x.first,x.second});
        }

        sort(v.begin(),v.end(),comp);
        
        unordered_set<int>set;
        int ans=0;
        for(int i=0;i<v.size();i++)
        {
           int freq=v[i].second;

           while(freq!=0 and set.find(freq)!=set.end())
           {
              ans++;
              freq-=1;
           }
           set.insert(freq);
        }
        return ans;
}


Solution 2-:


s = "aaabbbcc"

Steps-:
1)Here first we make a count array of 26 because charcter is of 26 and in array store the frequency in it.
2)Now make a hashset for storing the unique freq there and make a ans variable which increases when we delete.
3)Now run the whole count array and checking if that particular freq is present in hashset or not.
  Case1 -: Freq is present
  here we ans++ and decrease the freq-- 
  when this loop end then insert the freq into hashset for further iteartion.

  Case2-: Freq is not present
  Means no need for deletion 
  simply insert the freq in hashset


Code-:  Time Complexity ->O(n)  Space->O(n)
 int minDeletions(string s) {
        int count[26]={0};
        for(int i=0;i<s.length();i++)
        {
            count[s[i]-'a']++;
        }
        
        unordered_set<int>s1;
        int ans=0;
        for(int i=0;i<26;i++)
        {
            int freq=count[i];
            while(freq>0 and s1.find(freq)!=s1.end())
            {
                ans++;
                freq--;
            }
            s1.insert(freq);
        }
        return ans;
    }

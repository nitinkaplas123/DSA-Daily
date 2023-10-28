Solution 1-:
Reference->https://www.youtube.com/watch?v=D2GnunVezNA

Explanaion ->Notebook 1 page 32
Code-:
int mod=1e9+7;
    int numFactoredBinaryTrees(vector<int>& arr) {
        int n=arr.size();
        unordered_map<long long int,long long int>m;
        for(int i=0;i<n;i++)
        {
          m[arr[i]]=1;
        }
        
        sort(arr.begin(),arr.end());
        for(int i=1;i<n;i++)
        {
           long long int val=arr[i];
           for(int j=0;j<i;j++)
           {
              if(val%arr[j]==0)
              {
                if(m.find(val/arr[j])!=m.end())
                m[arr[i]]+=(m[arr[j]]%mod  * m[val/arr[j]] %mod)%mod;
              }
           }
        }

        long long int count=0;
        for(auto x:m)
        {
          count+=x.second%mod;
        }
        return count%mod;
    }
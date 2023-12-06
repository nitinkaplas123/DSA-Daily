Solution 1-:
Steps-:
1)Using hashmap

Code-: Time->O(N) Space->O(N)
vector<long long int> twoOddNum(long long int Arr[], long long int N)  
    {
      unordered_map<int,int>m;
      for(int i=0;i<N;i++)
      {
          m[Arr[i]]++;
      }
       
      vector<long long>v;
      for(auto x:m)
      {
          if(x.second%2!=0)
          v.push_back(x.first);
      }
      if(v[0]>v[1])
      return v;
      else
      return {v[1],v[0]};
      
    }
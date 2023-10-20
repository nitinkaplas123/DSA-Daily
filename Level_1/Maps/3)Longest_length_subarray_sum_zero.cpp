C++ -:

steps-:
Make a map (sum,index)  using m.insert({sum,index})


Code-:
int maxLen(vector<int>&A, int n)
    {   
      unordered_map<int,int>m;
      m.insert({0,-1});
      
      int sum=0;
      int ans=0;
      for(int i=0;i<n;i++)
      {
          sum+=A[i];
          if(m.find(sum)!=m.end())
          ans=max(ans,i-m[sum]);
          
          m.insert({sum,i});
      }
      return ans;
    }


Js-:

maxLen(arr,n){
      let m=new Map()
      let sum=0
      let ans=0
      m.set(0,-1)
      for(let i=0;i<n;i++) 
      {
          sum+=arr[i]
          if(m.has(sum))
          ans=Math.max(ans,i-m.get(sum))
          else
          m.set(sum,i)
      }
      return ans
    }

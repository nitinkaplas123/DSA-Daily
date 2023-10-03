 Solution 1 -: Time ->O(n2)   Space ->O(1)
 
 Code-:
 int subarraysDivByK(vector<int>& nums, int k) {
        int ans=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            int sum=0;
            for(int j=i;j<n;j++)
            {
                sum+=nums[j];
                if(sum%k==0)
                ans++;
            }
        }
        return ans;
    }


Solution 2-:

Steps-:
1) we make map here for storing rem and frequency of it .
2) we also use prefix sum and to get rem of it by (sum%k) 
3) If rem is -ve make it positive by adding k in it 
4) if the rem is already present in map then ans+=m[rem] (means adding its freq) and then increase it freq by 1
5) At last just return the ans 


Diagram refer to nootebbok 1 page no. 27

Code-:
int subarraysDivByK(vector<int>& nums, int k) {
         int n=nums.size();
         unordered_map<int,int>m;
         m[0]=1;
         
         int sum=0;
         int ans=0;
         int rem;
         for(int i=0;i<n;i++)
         {
             sum+=nums[i];
             rem=sum%k;
             if(rem<0)
             rem=rem+k;
             
             if(m.find(rem)!=m.end())
             {
                 ans+=m[rem];
                 m[rem]++;
             }
             else
             m[rem]=1;
         }
         return ans;
    }


Js-:
var subarraysDivByK = function(nums, k) {
    let n=nums.length
    let m=new Map()

    m.set(0,1)
    let ans=0
    let sum=0
    let rem
    for(let i=0;i<n;i++)
    {
        sum+=nums[i]
        rem=sum%k
        if(rem<0)
        rem+=k
        
        if(m.has(rem))
        {
            ans+=m.get(rem)
            m.set(rem,(m.get(rem))+1)
        }
        else
        m.set(rem,1);
    }
    return ans
};
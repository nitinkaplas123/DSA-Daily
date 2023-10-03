Solution -:
Idea-:
1)Make all 0 to -1 in array 
2)Now make use of hashmap and using presum we can calculate the max length.

Code-:
int findMaxLength(vector<int>& nums) {
       int n=nums.size();
       for(int i=0;i<n;i++)
       {
           if(nums[i]==0)
           nums[i]=-1;
       }

       unordered_map<int,int>m;
       m.insert({0,-1});
       
       int ans=0;
       int sum=0;
       for(int i=0;i<n;i++)
       {
           sum+=nums[i];
           if(m.find(sum)!=m.end())
           ans=max(ans,i-m[sum]);
           else
           m.insert({sum,i});
       }
       return ans;
    }



Js-:
var findMaxLength = function(nums) {
    for(let i=0;i<nums.length;i++)
    {
        if(nums[i]==0)
        nums[i]=-1
    }

    let m=new Map()
    let sum=0
    let ans=0

    m.set(0,-1)

    for(let i=0;i<nums.length;i++)
    {
        sum+=nums[i]
        if(m.has(sum))
        ans=Math.max(ans,i-m.get(sum))
        else
        m.set(sum,i)
    }
    return ans
};

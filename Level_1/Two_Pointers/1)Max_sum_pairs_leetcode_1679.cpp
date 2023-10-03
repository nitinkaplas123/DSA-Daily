Solution 1 -:
Using Two Pointer 

Code-:  Time->O(Nlogn)  Space->O(1)
  int maxOperations(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int low=0;
        int high=n-1;
        int count=0;
        while(low<high)
        {
            int sum=nums[low]+nums[high];
            if(sum==k)
            {
              count++;
              low++;
              high--;
            }
            else if(sum<k)
            low++;
            else
            high--;
        }
        return count;
    }


Solution 2 -:

Using hashmap

Code-:  Time ->O(n)   Space->O(N)

int maxOperations(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>m;
        
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(m.find(k-nums[i])!=m.end())
            {
               count++;
               m[k-nums[i]]--;

               if(m[k-nums[i]]==0)
               m.erase(k-nums[i]);
            }
            else
            m[nums[i]]++;
        }
        return count;
    }



Js Code-:
var maxOperations = function(nums, k) {
    let m=new Map()
    
    let n=nums.length
    let count=0
    
    for(let i=0;i<n;i++)
    {
        if(m.has(k-nums[i]))
        {
            count++;
            // m[k-nums[i]]--;
            m.set(k-nums[i],(m.get(k-nums[i])-1))

            if(m.get(k-nums[i])==0)
            m.delete(k-nums[i])
        }
        else if(m.has(nums[i]))
        m.set(nums[i],m.get(nums[i])+1)
        else
        m.set(nums[i],1)
    }
    return count;
};
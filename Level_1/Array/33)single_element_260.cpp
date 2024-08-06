Solution 1-:
Steps-:
1)Using hashmap

Code-:
vector<int> singleNumber(vector<int>& nums) {
        vector<int>v;
        int n=nums.size();
        unordered_map<int,int>m;
        for(int i=0;i<n;i++)
        {
            m[nums[i]]++;
        }

        for(auto x:m)
        {
            if(x.second==1)
            v.push_back(x.first);
        }
        return v;
}


Solution 2-:
Steps-:
1)Find the xor of all array elements store in res.
2)Now calculate the set bit index of res.
  which means that particular bit both single occuring elements are making difference.
3)Now make two variable set and unset 
  return {set,unset}

Code-:
int helper(int val)
    {
        int i;
        for(i=0;i<32;i++)
        {
            int n=(val>>i)&1;
            if(n==1)
            break;
        }
        return i;
    }
    vector<int> singleNumber(vector<int>& nums) {
         vector<int>v;
         int n=nums.size();
         
         int res=0;
         for(int i=0;i<n;i++)
         {
            res^=nums[i];
         }

         int index=helper(res);

         int set=0;
         int unset=0;
         for(int i=0;i<n;i++)
         {
            if(((nums[i]>>index)&1)==0)
            unset^=nums[i];
            else
            set^=nums[i];
         }
         return {unset,set};
    }



Java -:
 public int[] singleNumber(int[] nums) {
        int n=nums.length;
        int []ans=new int[2];
        HashMap<Integer,Integer>m=new HashMap<>();
        for(int i=0;i<n;i++)
        {
            m.put(nums[i],m.getOrDefault(nums[i],0)+1);
        }
        
        int i=0;
        for(Map.Entry<Integer,Integer>entry:m.entrySet())
        {
            if(entry.getValue()==1)
            ans[i++]=entry.getKey();
        }
        return ans;
    }
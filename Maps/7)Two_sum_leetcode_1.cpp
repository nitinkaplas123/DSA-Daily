Solution -:

Code-:   Time Complexity->O(n)  Space->O(n)

 vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        unordered_map<int,int>m;
        for(int i=0;i<n;i++)
        {
           if(m.find(target-nums[i])!=m.end())
           return {m[target-nums[i]],i};
           else
           m.insert({nums[i],i});
        }
        return {};
    }


    
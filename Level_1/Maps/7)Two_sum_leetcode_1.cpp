Solution 1-:
Code-:
vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(nums[i]+nums[j]==target)
                return {i,j};
            }
        }
        return {-1,-1};
    }



Solution 2-:
Code-:
vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        unordered_map<int,int>m;
        int sum=0;
        for(int i=0;i<n;i++)
        {
            if(m.find(target-nums[i])!=m.end())
            return {i,m[target-nums[i]]};
            else
            m.insert({nums[i],i});
        }
        return {-1,-1};
    
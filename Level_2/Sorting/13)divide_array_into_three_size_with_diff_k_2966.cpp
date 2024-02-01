Solution 1-:
Steps-:
1)Here we sort the array because we need (nums[i]-nums[i-1]<=k)
  So nums[i-1] -> nums[i] here nums[i] should be just greater than nums[i-1] so that the given condition 
  nums[i]-nums[i-1]<=k should be satisfied.
2)In every array there is 3 elements 
  So here in 3 elements 
  num[0],num[1],num[2]

  difference bw every combination is <=k
  So if we check num[0]-num[1]<=k which means every combination is satisified.



Code-: Time ->O(Nlog(N))
vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());

        vector<vector<int>>v;
        
        for(int i=0;i<n;i+=3)
        {
           if(nums[i+2]-nums[i]<=k)
           v.push_back({nums[i],nums[i+1],nums[i+2]});
           else
           return {};
        }
        return v;
}
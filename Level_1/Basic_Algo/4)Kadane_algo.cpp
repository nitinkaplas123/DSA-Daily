Solution -1
Steps-:
1)Simply making each subarray and store max result in it.

Code-: Time->O(n2)  Space ->O(1)
int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int ans=INT_MIN;
        for(int i=0;i<n;i++)
        {
            int curr_sum=0;
            for(int j=i;j<n;j++)
            {
                curr_sum+=nums[j];
                ans=max(ans,curr_sum);
            }
        }
        return ans;
}

Solution -2:

Steps-:
1)max(Starting from new index or new index + previous prefix sum)

Code-:  Time->O(1)   Space ->O(1)
int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int curr_sum=nums[0];
        int ans=nums[0];
        for(int i=1;i<n;i++)
        {
            curr_sum=max(curr_sum+nums[i],nums[i]);
            ans=max(ans,curr_sum);
        }
        return ans;
    }
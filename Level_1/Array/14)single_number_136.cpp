Solution 1-:
Steps-:
1)using xor of all elements

Code-:
int singleNumber(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            ans=ans^nums[i];
        }
        return ans;
    }


Solution 2-:
Steps-:
1)Using map

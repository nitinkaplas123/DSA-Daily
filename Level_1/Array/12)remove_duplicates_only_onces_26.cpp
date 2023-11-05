Solution 1-:
Steps-:
1)Using same approach as we do in previous

Code-: Time->O(N) Space->O(1)
int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        if(n<=1) return n;
        int index=1;
        for(int i=1;i<n;i++)
        {
            if(nums[index-1]!=nums[i])
            {
                nums[index]=nums[i];
                index++;
            }
        }
        return index;
    }
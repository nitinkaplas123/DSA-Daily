Solution 1-:
Steps-:
1)Firstly checking if sorted 
2)then rotate by 1 and check again sorted or not.

Code-: Time->O(N^2)
bool sorted(vector<int>&nums)
{
        int n=nums.size();
        for(int i=1;i<n;i++)
        {
            if(nums[i]<nums[i-1])
            return false;
        }
        return true;
}

void rotate_by_one(vector<int>&nums)
{
        int n=nums.size();
        int temp=nums[0];
        for(int i=1;i<n;i++)
        {
            nums[i-1]=nums[i];
        }
        nums[n-1]=temp;
}

bool check(vector<int>& nums) 
{
        int n=nums.size();
        
        for(int i=1;i<n;i++)
        {
            if(sorted(nums))
            return true;
            else
            rotate_by_one(nums);
        }
        return (sorted(nums));
}
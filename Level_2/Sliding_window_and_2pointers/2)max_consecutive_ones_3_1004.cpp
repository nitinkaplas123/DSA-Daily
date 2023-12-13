Solution 1-:
Steps-:
1)Using two pointer approach.
2)low and high.
3)There is 3 cases-:
 3.1 -> if arr[high]==1 high++;
 3.2 -> if arr[high]==0 and k!=0 k-- high++;
 3.3 -> here we finished the k and arr[high]=0
        1st we store the ans.
        2nd if arr[low]==0 then k++
        3rd low++


Code-: Time->O(2*N)
int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int low=0;
        int high=0;
        int ans=0;
        while(high<n)
        {
            if(nums[high]==1)
            high++;
            else if(nums[high]==0 and k!=0)
            {
                k--;
                high++;
            }
            else
            {
                ans=max(ans,high-low);
                if(nums[low]==0)
                k++;
                low++;
            }
        }
        return max(ans,high-low);
    }
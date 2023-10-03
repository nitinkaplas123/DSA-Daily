Solution1-:

Steps-:
1)Make a left =0 and right as sum of array - arr[0];
2)Now check at a given position i left=left+arr[i-1] and right=right-arr[i];
3)If (left==right) return i;
4)Else return -1;


Code-:
int pivotIndex(vector<int>& nums) {
       int n=nums.size();
       int left=0;

       int right=0;
       for(int i=1;i<n;i++)
       {
         right+=nums[i];
       }
       
       if(left==right)
       return 0;

       for(int i=1;i<n;i++)
       {
         left=left+nums[i-1];
         right=right-nums[i];
         if(left==right)
         return i;
       }
       return -1;
    }

    
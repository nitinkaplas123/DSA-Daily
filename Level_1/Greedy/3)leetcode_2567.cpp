Solution 1-:
Steps-:
Observations
1)If two numbers are equal, low is 0. We'll use this to remove low from consideration
2)There are three possibilities to minimize score:
  1)Set least two elements as third least
  2)Set greatest two elements as third greatest
  3)Set least to second least and greatest to second greatest


If we make two numbers equal, we can make the low score equal to 0. So only thing left is to find minimum high score.
The high score will depend on the minimum and the maximum value in the array. So, we should either decrease the maximum values or increase the minimum values. There are three posibilitites:

We decrease the top two values to third highest value.
We increase the bottom two value to third smallest value.
We increase the bottom value to second smallest value and decrease the top value to second highest value.
In all the above cases, low will be 0.


Code-:
int minimizeSum(vector<int>& nums) {
        int n=nums.size();
        if(n==3)
        return 0;
        sort(nums.begin(),nums.end());
        int diff1=nums[n-2]-nums[1];
        int diff2=nums[n-1]-nums[2];
        int diff3=nums[n-3]-nums[0];
        return min(diff1,min(diff2,diff3));
}


Java-:
public int minimizeSum(int[] nums) {
       int n=nums.length;
       Arrays.sort(nums);
       if(n==3) return 0;
       int diff1=nums[n-2]-nums[1];
       int diff2=nums[n-1]-nums[2];
       int diff3=nums[n-3]-nums[0];
       return Math.min(diff1,Math.min(diff2,diff3));
    }
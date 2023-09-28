Solution 1-:
Steps-:
1)As we do in kadane algo same we are doing here as well.
2)using 2 loops we find all subarray and find the max of it.

Code-: Time->O(N2)
int maxProduct(vector<int>& nums)
{
        int n=nums.size();
        int res=INT_MIN;
        for(int i=0;i<n;i++)
        {
            int sum=1;
            for(int j=i;j<n;j++)
            {
                sum*=nums[j];
                res=max(res,sum);
            }
        }
        return res;
 }


Solution 2-:
Steps-:
1)Here we make maxi and mini as variable where maxi contain max subarray and mini contain min subarray.
2)We need mini subarray here bcz 
  eg. [-2,3,-4]
   
  1. i=0
     maxi=-2
     mini=-2
  2. i=1
     maxi=3
     mini=-6

  3. i=2 (-4)
     here element is -ve if we multiple by maxi which is 3 =>3*-4 
                                                           =>-12
     here if we multiple by mini which is -6 =>-6*-4 
                                             =>24

     So here thats why we need mini subarray as well

 3)when we encounter with -ve element then maxi become mini and mini become maximum.
   simply swap the maxi and mini for it.


Code-: Time->O(N)  Space ->O(1)
int maxProduct(vector<int>& nums) 
{
        int n=nums.size();
        int res=nums[0];
        int maxx=nums[0];
        int mini=nums[0];
        for(int i=1;i<n;i++)
        {
            if(nums[i]<0)
            {
                int temp=maxx;
                maxx=mini;
                mini=temp;
            }

            maxx=max(maxx*nums[i],nums[i]);
            mini=min(mini*nums[i],nums[i]);
            res=max(res,maxx);
        }
        return res;
 }                                                                                             
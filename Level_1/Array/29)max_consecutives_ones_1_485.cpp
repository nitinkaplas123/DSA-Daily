Solution 1-:
Steps-:
1)count++ if nums[i]==1.
2)if nums[i]==0 then store the ans and count=0.


Code-: Time->O(N)
int findMaxConsecutiveOnes(vector<int>& nums) {
       int n=nums.size();
       int ans=0;
       int count=0;
       for(int i=0;i<n;i++)
       {
           if(nums[i]==1)
           count++;
           else
           {
               ans=max(ans,count);
               count=0;
           }
       }
       return max(ans,count);
    }
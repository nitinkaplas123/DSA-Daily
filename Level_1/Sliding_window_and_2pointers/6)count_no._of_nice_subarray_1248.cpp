Reference-> Notebook 1 page no. 39


Solution 1-:
Steps-:
1)here we just convert the array elements into binary.
2)if element is even then nums[i]=0;
3)if element is odd then nums[i]=1;
4)Now this question is similar to ->count subarray sum equal to k.


Code-: Time->O(N) Space->O(N)
int numberOfSubarrays(vector<int>& nums, int k) {
       int n=nums.size();
       for(int i=0;i<n;i++)
       {
           if(nums[i]%2==0)
           nums[i]=0;
           else
           nums[i]=1;
       }

       unordered_map<int,int>m;
       int pre_sum=0;
       int count=0;
       for(int i=0;i<n;i++)
       {
          pre_sum+=nums[i];
          if(pre_sum==k) count++;
          if(m.find(pre_sum-k)!=m.end())
          count+=m[pre_sum-k];
          m[pre_sum]++;
       }
       return count;
    }


Solution 2-:
Steps-:
1)just do the dry run 


Code-: Time->O(2*N) Space->O(1)
int numberOfSubarrays(vector<int>& nums, int k) {
       int n=nums.size();
       int count=0;
       int odd=0;
       int low=0;
       int high=0;
       int ans=0;
       while(high<n)
       {
           // adding if element is odd
           if(nums[high]%2!=0)
           {
               odd++;
               count=0;
           }
           
           //here odd==k means this is our ans
           // and also compress from front 
           while(odd==k)
           {
               count++;
               odd=odd-(nums[low]&1);
               low++;
           }
           
           //adding all subarray count
           ans+=count;
           high++;
       }
       return ans;
    }
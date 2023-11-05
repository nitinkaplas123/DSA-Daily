Solution 1-:
Step-:
1)Store the elements in hashset.
2)Then find.


Code-:
 int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        vector<int>v;
        v.push_back(nums[0]);
        for(int i=1;i<n;i++)
        {
            if(nums[i]!=v.back())
            v.push_back(nums[i]);
        }

        for(int i=0;i<v.size();i++)
        {
            nums[i]=v[i];
        }
        return v.size();
    }



Solution 2-:
Steps-:
1)Using xor 

Code-:
int missingNumber(vector<int>& nums) {
       int ans=0;
       for(int i=0;i<nums.size();i++)
       {
           ans=ans^i^nums[i];
       }
       return ans;
    }
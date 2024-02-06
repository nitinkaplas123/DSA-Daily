Solution 1-:
Steps-:
1)Storing into vector v


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
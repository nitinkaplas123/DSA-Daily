Solution 1-:
Steps-:
1)Here we use extra space as vector 
2)for atmost 2 repeating element we use count variable for checking and compare with previous element.

Code-: Time->O(N) Space ->O(N)
int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int count=1;
        vector<int>v;
        v.push_back(nums[0]);
        for(int i=1;i<n;i++)
        {
            if(nums[i]==nums[i-1] and count!=2)
            {
                count++;
                v.push_back(nums[i]);
            }
            else if(nums[i]!=nums[i-1])
            {
               count=1;
               v.push_back(nums[i]);
            }
            else
            continue;
        }

        for(int i=0;i<v.size();i++)
        {
            nums[i]=v[i];
        }
        return v.size();
    }



Solution 2-:
Steps-:
1)Using low and high pointers and for atmost 2 same we use count varible.


Code-:Time->O(N) Space ->O(1)
int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int count=1;
        int low=0;
        int high=1;
        while(high<n)
        {
            if(nums[low]==nums[high] and count!=2)
            {
                count++;
                low++;
                nums[low]=nums[high];
                high++;
            }
            else if(nums[low]!=nums[high])
            {
                count=1;
                low++;
                nums[low]=nums[high];
                high++;
            }
            else
            high++;
        }
        return low+1;
    }



Solution 3-:
Simple question in less lines-:
Steps-:
1)Here we use index variable which is pointer to which over ans is there from 0 to index.
2)Here we check if nums[i]!=nums[index-2]  bcz we need two atmost and we have to check 

Reference ->https://www.youtube.com/watch?v=drbtmYjZQHQ
Code-:
 int removeDuplicates(vector<int>& nums) {
       int n=nums.size();
       if(n<=2) return n;
       int index=2;
       for(int i=2;i<nums.size();i++)
       {
           if(nums[i]!=nums[index-2])
           {
               nums[index]=nums[i];
               index++;
           }
       }
       return index;
    }


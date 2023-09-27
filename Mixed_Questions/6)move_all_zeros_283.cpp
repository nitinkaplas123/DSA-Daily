Solution 1-:
Steps-:
1)We make a vector res and traverse a loop if element is !=0 then put into res and make a count of 0 in loop.
2)Now using while loop count-- we put the 0 into the end of vector res.


Code-: Time->O(N)  Space ->O(N)
void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        vector<int>v;

        int count=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]!=0)
            v.push_back(nums[i]);

            if(nums[i]==0)
            count++;
        }

        while(count--)
        {
            v.push_back(0);
        }
        nums=v;
    }





Solution 2-:
using lomoto parition 

Steps-:
1)Traverse the loop if we have element other then 0 then swap current element with i++;

Code-: Time->O(n)  Space->O(1)
void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        int i=-1;
        for(int j=0;j<n;j++)
        {
            if(nums[j]!=0)
            {
                i++;
                swap(nums[i],nums[j]);
            }
        }
    }

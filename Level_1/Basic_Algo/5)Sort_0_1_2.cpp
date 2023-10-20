This algo is called National Dutch Algorithms

Steps-:
1)From 0 to low we have all 0 elements.
2)From low to mid we have all 1 elements.
3)From mid to n-1 we have all 2 elements.
4)Here we break when mid cross high 


Code-:  Time->O(N)   Space ->O(1)
void sortColors(vector<int>& nums) {
        int n=nums.size();
        int low=0;
        int mid=0;
        int high=n-1;
        while(mid<=high)
        {
            if(nums[mid]==0)
            {
                swap(nums[low],nums[mid]);
                low++;
                mid++;
            }
            else if(nums[mid]==1)
            mid++;
            else
            {
                swap(nums[mid],nums[high]);
                high--;
            }
        }
    }



Solution 2-:
Steps-:
1)Using lomuto partition

Code-:
 void sortColors(vector<int>& nums) {
       int n=nums.size();
       int i=-1;
       for(int j=0;j<n;j++)
       {
           if(nums[j]==0)
           {
              i++;
              swap(nums[i],nums[j]);
           }
       }
       int index=i;
       for(int j=index+1;j<n;j++)
       {
           if(nums[j]==1)
           {
               i++;
               swap(nums[i],nums[j]);
           }
       }
    }
Solution 1-:
Steps-:
1)Sort the array and multiple last two elements.


Code-: Time->O(Nlog(N))
  int maxProduct(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());

        int ans=0;
        return (nums[n-2]-1) * (nums[n-1]-1);
    }





Solution 2-:
Steps-:
1)here we use the concept of second largest element question.
2)But we  have to take care of case when [1,5,5,3] duplicate max elements are there.
  here 5 is the first largest and 3 is the second largest 
  but we need max two elements to make ans maximum 
  so here 
  5 is the first largest 
  5 is the second largest.


Code-: Time->O(N)
int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int first=-1;
        int second=-1;
        for(int i=0;i<n;i++)
        {
            if(nums[i]>first)
            {
                second=first;
                first=nums[i];
            }
            else if(nums[i]>second )
            second=nums[i];
            else
            continue;
        }
        return (first-1) * (second-1);
    }
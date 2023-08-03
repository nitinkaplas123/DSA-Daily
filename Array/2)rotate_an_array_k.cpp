// Solution -1

Steps-:
1) Write a code for Rotate the array by 1 element
2) In main code run for loop k times and call the steps1 code there.

code-:
void helper(vector<int>&nums,int n)
    {
      int save=nums[n-1];
      for(int i=n-2;i>=0;i--)
      {
         nums[i+1]=nums[i];
      }
      nums[0]=save;
    }
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        for(int i=0;i<k;i++)
        {
           helper(nums,n);
        }
    }


// Solution -2

Steps-:
Here we have to check the k should always be smaller then the length of array.
k=k%n;

1) reverse the array from (0,n-k-1)
2) reverse the array from (n-k,n-1);
3) reverse the array from (0,n-1);

Code-:

void reverse(vector<int>&nums,int i,int j)
    {
        while(i<j)
        {
          swap(nums[i],nums[j]);
          i++;
          j--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k=k%n;
       
        reverse(nums,0,n-k-1);
        reverse(nums,n-k,n-1);
        reverse(nums,0,n-1);
    }


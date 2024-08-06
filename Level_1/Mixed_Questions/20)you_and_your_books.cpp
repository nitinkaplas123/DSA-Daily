Question -> https://www.geeksforgeeks.org/problems/you-and-your-books/1

Solution 1-:
Steps-:
1)Just make a ans variable and sum variable 
2)Find the sum of consecutive elements those arr[i]<=k and 
  if we find the element which is greater than k 
  we take the max(ans,sum) and reintialise the sum=0;


Code-: Time ->O(N) Space->O(1)
int max_Books(int arr[], int n, int k) {
        int ans=0;
        int sum=0;
        for(int i=0;i<n;i++)
        {
            if(arr[i]<=k)
            sum+=arr[i];
            else
            {
                ans=max(ans,sum);
                sum=0;
            }
        }
        return max(ans,sum);
}
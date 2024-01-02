Question ->https://www.geeksforgeeks.org/problems/largest-sum-subarray-of-size-at-least-k3121/1

Solution 1-:
Steps-:
1)using 2 for loop.
2)here if size of subarray>=k we can store the max sum 

Code-: Time->O(N^2) Space->O(1)
long long int maxSumWithK(long long int a[], long long int n, long long int k) 
{
        int ans=INT_MIN;
        for(int i=0;i<n;i++)
        {
            int sum=a[i];
            for(int j=i+1;j<n;j++)
            {
                sum+=a[j];
                if(j-i+1>=k)
                ans=max(ans,sum);
            }
        }
        return ans;
}
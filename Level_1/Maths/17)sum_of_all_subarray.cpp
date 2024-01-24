question ->https://www.geeksforgeeks.org/problems/sum-of-subarrays2229/1


Solution 1-:
Steps-:
1)Using two pointers
2)Here we clearly see we are using 2 pointer appraoch.
  start and end.
  where start pointing to starting of the index and ending point to end of the array
3) here loop i denotes the starting point of the loop.
4) here loop j denotes the ending point of the loop.
5) solve function print the subarray from (i to j index).


Code-: Time->O(N^3) Space->O(1)
long long subarraySum(long long a[], long long n)
    {
      long long ans=0;
      for(int i=0;i<n;i++)
      {
          for(int j=i;j<n;j++)
          {
              for(int k=i;k<=j;k++)
              {
                  ans+=a[k];
              }
          }
      }
      return ans;
}



Solution 2-:
Steps-:
[1,2,3]

1st-:
s1=1
s2=1+2=> 3
s3=3+3=> 6

2nd-:
s1=2
s2=2+3=> 5

3rd
s1=3

Code-: Time->O(N^2)
int mod=1e9+7;
long long subarraySum(long long a[], long long n)
    {
      long long ans=0;
      for(int i=0;i<n;i++)
      {
          long long int sum=0;
          for(int j=i;j<n;j++)
          {
              sum+=a[j];
              ans+=sum%mod;
          }
      }
      return ans%mod;
}


Solution 3-:
Steps-:
[1,2,3,4]

print all subarray-:
[1] [1,2] [1,2,3] [1,2,3,4]
[2] [2,3] [2,3,4]
[3] [3,4]
[4]

count all 
1 -> 4times
2 -> 6times
3 -> 6times
4 -> 4times

Steps-:
1) count occurances as starting with number.  right side of array 
2) count occurances without starting.         left side of array.

right side-> [n-i]   times.
left side -> [n-i]*i times.

Code-: Time->O(N)
int mod=1e9+7;
long long subarraySum(long long a[], long long n)
{
      long long ans=0;
      long long left,right;
      for(int i=0;i<n;i++)
      {
          right=n-i;
          left=(n-i)*i;
          ans+=((left+right)*a[i])%mod;
      }
      return ans%mod;
}




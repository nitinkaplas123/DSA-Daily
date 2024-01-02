Question ->https://www.geeksforgeeks.org/problems/largest-sum-subarray-of-size-at-least-k3121/1

Reference-> https://www.youtube.com/watch?v=OodoQ95se20

Reference-> Notebook 1 Page No. 46
Solution 1-:
Steps-:
1)using 2 for loop.

Code-:
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


Solution 2-:

Steps-:
1)Here we are using kadane algo. store the max subarray sum in kadane_arr array.
2)here if we have k=2 
  then we sum up of every window k which is called exact k elements 
  but in question atleast k is there which means we can take morethan k elements 
3)When we have sum of exact k window now 
  There is 2 cases-:
  1) include the left side subarray
  2) not include the left side subarray
4) if kadane_arr[i-k]>0 which is just left which means if by adding this  will make my sum greater
   then we include it.
   else 
   we ignore it.




Code-: Time-> O(N) Space->O(N)
long long int maxSumWithK(long long int a[], long long int n, long long int k) 
    {
        long long ans=0;
        long long int arr[n];
        arr[0]=a[0];
        long long int curr_sum=a[0];
        
        for(int i=1;i<n;i++)
        {
            curr_sum=max(curr_sum+a[i],a[i]);
            arr[i]=curr_sum;
        }
        
        long long int sum=0;
        for(int i=0;i<k;i++)
        {
            sum+=a[i];
        }
        
        long long res=sum;
        long long int low=0;
        long long int high=k;
        while(high<n)
        {
            sum+=a[high];
            sum-=a[low];
            
            long long int curr_sum=sum;
            if(arr[high-k]>0)
            curr_sum+=arr[high-k];
            
            res=max(res,curr_sum);
          
            low++;
            high++;
        }
        return res;
    }
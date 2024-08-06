Solution 1-:
Steps-:
1) using 2 for loop we have to neglect the subarray size 

Code-:
int minimizeDifference(int n, int k, vector<int> &arr) 
{
        int ans=INT_MAX;
        for(int i=0;i<=n-k;i++)
        {
            int mini=INT_MAX;
            int maxi=INT_MIN;
            for(int j=0;j<n;j++)
            {
                if((j<i) || (j>k-1+i))
                {
                    maxi=max(maxi,arr[j]);
                    mini=min(mini,arr[j]);
                }
            }
            ans=min(ans,maxi-mini);
        }
        return ans;
}


Solution 2-:
Steps-:

Code-:
int post_min[n];
       int post_max[n];
       
       post_min[n-1]=arr[n-1];
       post_max[n-1]=arr[n-1];
       
       for(int i=n-2;i>=0;i--)
       {
           post_min[i]=min(arr[i],post_min[i+1]);
           post_max[i]=max(arr[i],post_max[i+1]);
       }
       
       int ans=post_max[k]-post_min[k];
       int left_min=arr[0];
       int left_max=arr[0];
       
       for(int i=1;i<n-k;i++)
       {
           int maxi=max(left_max,post_max[i+k]);
           int mini=min(left_min,post_min[i+k]);
           
           ans=min(ans,maxi-mini);
           
           left_min=min(left_min,arr[i]);
           left_max=max(left_max,arr[i]);
       }
       return min(ans,left_max-left_min);
}
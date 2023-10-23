Solution 1-:
Steps-:
1)Make each possible two values using 2 loops

Code-:
long long maxArea(long long A[], int len)
{
    int ans=INT_MIN;
    for(int i=0;i<len;i++)
    {
        for(int j=i+1;j<len;j++)
        {
            int index_diff=j-i;
            int mini=min(A[i],A[j]);
            ans=max(ans,index_diff*mini);
        }
    }
    return ans;
}


Solution 2-:

Steps-:
1)Make using end points because we need max water for that we need max width.
2)For max water we also need max heights from both end.
3)For that condition is if rmax<lmax which means lmax is the max so we have to change right pos to high-- and 
  vice versa

Code-: Time->O(N)   Space->O(1)
long long maxArea(long long A[], int len)
{
    int ans=0;
    int low=0;
    int high=len-1;
    while(low<high)
    {
        int index=high-low;
        int mini=min(A[high],A[low]);
        ans=max(ans,index*mini);
        
        if(A[low]<A[high])
        low++;
        else
        high--;
    }
    return ans;
}


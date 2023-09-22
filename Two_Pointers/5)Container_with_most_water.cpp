Solution -1

Steps-:
1)Make using end points because we need max water for that we need max width.
2)For max water we also need max heights from both end.
3)For that condition is if rmax<lmax which means lmax is the max so we have to change right pos to high-- and 
  vice versa

Code-: Time->O(N)   Space->O(1)
nt maxArea(vector<int>& height) {
        int n=height.size();
        int ans=0;
        
        int lmax=INT_MIN;
        int rmax=INT_MIN;
        int low=0;
        int high=n-1;
        while(low<=high)
        {
            lmax=max(lmax,height[low]);
            rmax=max(rmax,height[high]);
            int mini=min(lmax,rmax);
            ans=max(ans,mini*(high-low));
           
            if(lmax<rmax)
            low++;
            else
            high--;
        }
        return ans;
    }


Solution 1-:
Steps-:
1)Here at every step we update buy and find  ans=max(ans,nums[i]-buy);

Code-: Time->O(N)
int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int mini=prices[0];
        int ans=0;
        for(int i=1;i<n;i++)
        {
           ans=max(ans,prices[i]-mini);
           mini=min(mini,prices[i]);
        }
        return ans;
    }
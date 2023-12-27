Solution 1-:
Steps-:
1)here we compare i element with i-1 if charcter are  equal then we have to take the min time into our ans.
2)here we compare with adjacent string charcter but we have to take time min and 
  we have to update the prev max time in neededTime[i] so that in next interval it become neededTime[i-1]


Just do the dry run 
for str="aaaaaaa"
    time=[1,2,1,5,1,1,6]


Code-: Time->O(N)
int minCost(string colors, vector<int>& neededTime) {
        int n=colors.size();
        int ans=0;
        for(int i=1;i<n;i++)
        {
           if(colors[i]==colors[i-1])
           {
              ans+=min(neededTime[i],neededTime[i-1]);
              neededTime[i]=max(neededTime[i],neededTime[i-1]);
           }
        }
        return ans;
}
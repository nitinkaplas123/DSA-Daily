Solution 1-:
Steps-:
1)Using simple sort function.

Code-: Time->O(Nlog(N)) Space->O(1)
int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int count=0;
        for(int i=0;i<costs.size();i++)
        {
            if(coins>=costs[i])
            {
                count++;
                coins-=costs[i];
            }
        }
        return count;
}


Solution 2-:
Steps-:
1)using counting sort.
mixed questions -> 4 
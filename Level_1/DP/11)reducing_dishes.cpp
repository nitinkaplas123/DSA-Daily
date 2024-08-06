Solution 1-:
Steps-:
1)

Code-:
int helper(vector<int>& satisfaction,int index,int time,int n)
{
        if(index==n)
        return 0;

        int include=satisfaction[index]*time + 
                    helper(satisfaction,index+1,time+1,n);
        int exclude=helper(satisfaction,index+1,time,n);
        return max(include,exclude);
}

int maxSatisfaction(vector<int>& satisfaction) {
        int n=satisfaction.size();
        sort(satisfaction.begin(),satisfaction.end());
        int index=0;
        int time=1;
        return helper(satisfaction,index,time,n);
}

Solution 2-:
Steps-:
1)Memoization 

Code-:
int helper(int memo[501][501],vector<int>& satisfaction,
               int index,int time,int n)
{
        if(index==n)
        return 0;
        if(memo[time][index]!=-1) return memo[time][index];
        
        int res;
        int include=satisfaction[index]*time + 
                    helper(memo,satisfaction,index+1,time+1,n);
        int exclude=helper(memo,satisfaction,index+1,time,n);
        res= max(include,exclude);
        return memo[time][index]=res;
}

int maxSatisfaction(vector<int>& satisfaction) {
        int n=satisfaction.size();
        int memo[501][501];
        memset(memo,-1,sizeof(memo));
        sort(satisfaction.begin(),satisfaction.end());
        int index=0;
        int time=1;
        return helper(memo,satisfaction,index,time,n);
}
Solution 1-:
Steps-:
1) using recursion


Code-:
int climbStairs(int n) {
        if(n==0) return 1;
        if(n<0) return 0;

        return climbStairs(n-1) + climbStairs(n-2);
}



Solution 2-:
Steps-:
1)using memoization 


Code-: Time->O(N) Space->O(N)
int helper(int memo[46],int n)
{
        if(n==0) return 1;
        if(n<0) return 0;

        if(memo[n]!=-1) return memo[n];

        int val1=helper(memo,n-1);
        int val2=helper(memo,n-2);
        return memo[n]=val1+val2;
}

int climbStairs(int n) {
        int memo[46];
        memset(memo,-1,sizeof(memo));
        return helper(memo,n);
}


Solution 3-:
Steps-:
1)using tabulation method 


int climbStairs(int n){
        int dp[n+1];
        dp[0]=1;
        dp[1]=1;

        for(int i=2;i<=n;i++)
        {
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
}
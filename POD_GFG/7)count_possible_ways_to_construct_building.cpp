Reference->https://www.geeksforgeeks.org/problems/count-possible-ways-to-construct-buildings5007/1

Video-> https://www.youtube.com/watch?v=VQAp7AQ8JcM


Solution 1-:
1)Using recusrion 



Code-:
int mod=1e9+7;
int helper(int N,int status)
{
	    if(N==0) return 1;
	    
	    if(status==1)
	    return helper(N-1,0)%mod;
	    else
	    return (helper(N-1,0)%mod + helper(N-1,1)%mod)%mod;
}
	
int TotalWays(int N)
{
	    int building=1;
	    int space=0;
	    
	    long long res1=helper(N-1,1);
	    long long res2=helper(N-1,0);
	    long long res=(res1%mod+res2%mod)%mod;
	    return (res%mod*res%mod)%mod;
}



Solution 2-: Using memoization 
Steps-:
1)



Code-:
int mod=1e9+7;
int helper(int memo[100001][2],int N,int status)
{
	    if(N==0) return 1;
	    if(memo[N][status]!=-1) return memo[N][status];
	    
	    int res;
	    
	    if(status==1)
	    res= helper(memo,N-1,0)%mod;
	    else
	    res= (helper(memo,N-1,0)%mod + helper(memo,N-1,1)%mod)%mod;
	    return memo[N][status]=res;
}
	
int TotalWays(int N)
{
	    int building=1;
	    int space=0;
	    int memo[100001][2];
	    memset(memo,-1,sizeof(memo));
	    
	    long long res1=helper(memo,N-1,1);
	    long long res2=helper(memo,N-1,0);
	    long long res=(res1%mod+res2%mod)%mod;
	    return (res%mod*res%mod)%mod;
}
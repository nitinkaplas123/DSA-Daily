Solution 1-:
Steps-:
1)here we have to see all the possible ways for each dice.
2)Like if there is n=3 and k=6 then for -:
  Dice 1-:  we check for k cases i=1 to i=k  i=1 i=2 i=3 i=4 i=5 i=6
  Dice 2-:  we check for k cases i=1 to i=k  here i=1 go 6 times i=2 check for 6 times ans so on 
  Dice 3-:  we check for k cases i=1 to i=k

Code-: Time->O(K^N) 
int mod=1e9+7;
int helper(int n,int k,int target)
{
        if(n==0)
        {
            if(target==0)
            return 1;
            else
            return 0;
        }
        
        int ways=0;
        for(int i=1;i<=k;i++)
        {
           ways+=helper(n-1,k,target-i);
        }
        return ways;
}

int numRollsToTarget(int n, int k, int target) {
        return helper(n,k,target);
 }



Solution 2-:
Steps-:
1)Here we do memoization 
2)In up sol. there is 2 varibles which are changing.
3)N no. of dices and target so we make memo of it.

Code-:
int mod=1e9+7;
int helper(int memo[31][1001],int n,int k,int target)
{
        if(target<0) return 0;
        if(n==0) return (target==0);

        if(memo[n][target]!=-1) return memo[n][target];
        
        int ways=0;
        for(int i=1;i<=k;i++)
        {
           ways+=helper(memo,n-1,k,target-i);
           ways=ways%mod;
        }
        return memo[n][target]=ways;
}

int numRollsToTarget(int n, int k, int target){
       int memo[31][1001];
       memset(memo,-1,sizeof(memo));
       return helper(memo,n,k,target);
}
https://practice.geeksforgeeks.org/problems/find-optimum-operation4504/1

Solution 1-:
Steps-:
1)here we have 2 options either 1st choose or 2nd choose.
2)This give us idea that we can use dp here.

Code-: Using recusrion

 int minOperation(int n)
    {
       if(n==0)
       return 0;
       
       else if(n%2==0)
       return 1+minOperation(n/2);
       else
       return 1+minOperation(n-1);
    }

Solution 2-;
Steps-:
using memoization

Code-:
int helper(int memo[1000001],int n)
{
        int res;
        if(n==0)
        return 0;
        else if(memo[n]!=-1)
        return memo[n];
        else if(n%2==0)
        res=1+helper(memo,n/2);
        else
        res=1+helper(memo,n-1);
        
        return memo[n]=res;
}

int minOperation(int n)
{
       int memo[1000001];
       memset(memo,-1,sizeof(memo));
       return helper(memo,n);
}


Solution 3-:
Steps-:
1)simple doing while loop for both 2 opeartions.

Code-:
int minOperation(int n)
{
       int count=0;
       while(n!=0)
       {
           if(n%2==0)
           n=n/2;
           else
           n--;
           count++;
       }
       return count;
}
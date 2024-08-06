Question ->https://www.geeksforgeeks.org/problems/minimum-cost-to-make-two-strings-identical1107/1

Solution 1-:
Steps-:
1)Using LCS.

s1="abcd"
s2="acdb"
costX=10
costY=20

2)find the lcs -> (abcd,acdb)
             -> acd 

3)Now delete charcters 
  int a=(n-lcs) 
       =(4-3)
       =1 * costA
       =10
 
  int b=(m-lcs)
       =(4-3)
       =1 * costB
       =20

4)Return a+b;
  O/P -> 30



Code-:
int LCS(int memo[1001][1001],string &s1,string &s2,int n,int m)
{
        int res;
        if(n==0 || m==0)
        return 0;
        if(memo[n][m]!=-1)
        return memo[n][m];
        
        if(s1[n-1]==s2[m-1])
        res= 1+LCS(memo,s1,s2,n-1,m-1);
        else
        res= max(LCS(memo,s1,s2,n-1,m),LCS(memo,s1,s2,n,m-1));
        return memo[n][m]=res;
}
   
int findMinCost(string x, string y, int costX, int costY) {
        int n=x.length();
        int m=y.length();
        int memo[1001][1001];
        memset(memo,-1,sizeof(memo));
        int lcs=LCS(memo,x,y,n,m);
        int a=(n-lcs)*costX;
        int b=(m-lcs)*costY;
        return a+b;
}    
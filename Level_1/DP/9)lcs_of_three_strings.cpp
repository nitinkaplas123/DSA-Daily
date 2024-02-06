Solution 1-:
Steps-:
1)Using recusrion 
2)Same approach as we do in lcs of two strings.
3)Now compare with s1 with s2 and s2 with s3.

Code-:
int helper(string A,string B,string C,int n1,int n2,int n3)
{
            if(n1==0 || n2==0 || n3==0) return 0;
            
            if(A[n1-1]==B[n2-1] and B[n2-1]==C[n3-1])
            return 1+helper(A,B,C,n1-1,n2-1,n3-1);
            else
            {
                int val1=helper(A,B,C,n1-1,n2,n3);
                int val2=helper(A,B,C,n1,n2-1,n3);
                int val3=helper(A,B,C,n1,n2,n3-1);
                return max(val1,max(val2,val3));
            }
}

int LCSof3 (string A, string B, string C, int n1, int n2, int n3)
{
            return helper(A,B,C,n1,n2,n3);
}




Solution 2-:
Steps-:
1)Using memoization.

Code-: Time->O(N1*N2*N3)
int helper(int memo[21][21][21],string A,string B,string C,int n1,int n2,int n3)
{
            if(n1==0 || n2==0 || n3==0) 
            return 0;
            
            if(memo[n1][n2][n3]!=-1) 
            return memo[n1][n2][n3];
            
            int res;
            if(A[n1-1]==B[n2-1] and B[n2-1]==C[n3-1])
            res=1+helper(memo,A,B,C,n1-1,n2-1,n3-1);
            else
            {
                int val1=helper(memo,A,B,C,n1-1,n2,n3);
                int val2=helper(memo,A,B,C,n1,n2-1,n3);
                int val3=helper(memo,A,B,C,n1,n2,n3-1);
                res= max(val1,max(val2,val3));
            }
            return memo[n1][n2][n3]=res;
}

int LCSof3 (string A, string B, string C, int n1, int n2, int n3)
{
            int memo[21][21][21];
            memset(memo,-1,sizeof(memo));
            return helper(memo,A,B,C,n1,n2,n3);
}




Solution 3-:
Steps-:
1)Using tabulation 


Code-: Time->O(N1*N2*N3)
int LCSof3 (string A, string B, string C, int n1, int n2, int n3)
{
            int dp[n1+1][n2+1][n3+1];
            for(int i=0;i<=n1;i++)
            {
                for(int j=0;j<=n2;j++)
                {
                    for(int k=0;k<=n3;k++)
                    {
                        if(i==0 || j==0 || k==0) 
                        dp[i][j][k]=0;
                        else if(A[i-1]==B[j-1] and B[j-1]==C[k-1])
                        dp[i][j][k]=1+dp[i-1][j-1][k-1];
                        else
                        dp[i][j][k]=max(dp[i-1][j][k],max(dp[i][j-1][k],dp[i][j][k-1]));
                    }
                }
            }
            return dp[n1][n2][n3];
}
Solution 1-:
Steps-:
1)Make a dp array of size dp[n][n]

suppose n=5
[1,0,0,0,0]
[1,1,0,0,0]
[1,2,1,0,0]
[1,3,3,1,0]
[1,4,6,4,1]

Case-:
1)here we see when j=0 our dp[i][j]=1
2)here we make first row only with the help of it we can make further more
  if(i==0) dp[i][j]=0;
3)for rest dp[i][j]=dp[i-1][j-1]+dp[i-1][j]


Code-: Time->O(N^2)
vector<vector<int>> generate(int numRows) {
         int n=numRows;
         int dp[n][n];

         for(int i=0;i<n;i++)
         {
             for(int j=0;j<n;j++)
             {
                 if(j==0)
                 dp[i][j]=1;
                 else if(i==0)
                 dp[i][j]=0;
                 else
                 dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
             }
         }

         vector<vector<int>>v;
         vector<int>v1;
         for(int i=0;i<n;i++)
         {
             for(int j=0;j<=i;j++)
             {
                v1.push_back(dp[i][j]);
             }
             v.push_back(v1);
             v1.clear();
         }
         return v;
    }

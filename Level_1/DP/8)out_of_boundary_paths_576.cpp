Solution 1-;
Steps-:
1)using recursion.
2)As in question said to go out of boundary we have 4  directions -> left,right,top,bottom.
Base Case-:
1)When we are out of bound -> return 1
2)when our moves =0       -> return 0 bcz we cannot go further.

Rest-> code-:
1)here we go in 4 direction-:
  ans->left+right+top+bottom;


Code-: Time Complexity->O(3^N)
int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        if(startColumn<0 || startColumn>=n)
        return 1;
        if(startRow<0 || startRow>=m)
        return 1;
        if(maxMove==0) return 0;

        int left=findPaths(m,n,maxMove-1,startRow,startColumn-1);
        int right=findPaths(m,n,maxMove-1,startRow,startColumn+1);
        int top=findPaths(m,n,maxMove-1,startRow-1,startColumn);
        int bottom=findPaths(m,n,maxMove-1,startRow+1,startColumn);

        return left+right+top+bottom;
}



Solution 2-:
Steps-:
1)using memoization 


Code-: Time Complexity->O(M*N*Moves)

int mod=1e9+7;
    int helper(int memo[51][51][51], int m, int n, int i, int j, int moves) {
    if (j < 0 || j >= n) return 1;
    if (i < 0 || i >= m) return 1;
    if (moves == 0) return 0;  

    if (memo[i][j][moves] != -1) return memo[i][j][moves];

    long long int left = helper(memo, m, n, i, j - 1, moves - 1);
    long long int right = helper(memo, m, n, i, j + 1, moves - 1);
    long long int top = helper(memo, m, n, i - 1, j, moves - 1);
    long long int bottom = helper(memo, m, n, i + 1, j, moves - 1);
    long long int ans = (left + right + top + bottom) % mod;

    return memo[i][j][moves] = ans%mod;
}

int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
    int memo[51][51][51];
    memset(memo, -1, sizeof(memo));
    return helper(memo, m, n, startRow, startColumn, maxMove);
 }


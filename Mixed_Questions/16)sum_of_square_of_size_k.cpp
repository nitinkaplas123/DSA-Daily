Question link-:
https://www.codingninjas.com/studio/problems/print-all-kxk_893291?utm_source=youtube&utm_medium=affiliate&utm_campaign=parikh_youtube&leftPanelTab=1

Solution 1 -:
Steps-:
The operations look like this:
1)Traverse the matrix, suppose we are at the ith row and jth column.
2)A sub-matrix is possible with this index as top-left corner only if i+K < N and j+K < N. If it is a possible sub-matrix, then run 2 nested loops to find the sum of elements from row i, i+K and column j, j+K.
3)Store this sum in ANS[i][j].
4)Continue this process.
5)Return ANS.

Code-:
vector<vector<int>> sumOfKxKMatrices(vector<vector<int>> &arr, int k){
    int n=arr.size();
    vector<vector<int>>ans(n-k+1,vector<int>(n-k+1));

    for(int i=0;i<=n-k;i++)
    {
        for(int j=0;j<=n-k;j++)
        {
            int sum=0;
            for(int x=0;x<k;x++)
            {
                for(int y=0;y<k;y++)
                {
                    sum+=arr[i+x][j+y];
                }
            }
            ans[i][j]=sum;
        }
    }
    return ans;
}



Solution 2-:
Steps-:
1)
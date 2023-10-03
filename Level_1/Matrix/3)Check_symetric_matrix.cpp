question link-:
https://www.codingninjas.com/studio/problems/matrix-is-symmetric_799361?utm_source=youtube&utm_medium=affiliate&utm_campaign=parikh_youtube&leftPanelTab=1

steps-:  Time Complexity ->O(n*n) Space  ->O(1)
For symmtric matrix means transpose
1)For symmtric cocndition will be matrix[i][j]==matrix[j][i] alaways
2)If at any stage matrix[i][j]!=matrix[j][i]  return false

Code-:
bool isMatrixSymmetric(vector<vector<int>> matrix){
     vector<vector<int>>v;
     int n=matrix.size();
     int m=matrix[0].size();
     
     for(int i=0;i<n;i++)
     {
        for(int j=i;j<n;j++)
        {
            if(matrix[i][j]!=matrix[j][i])
            return false;
        }
     }
     return true;
}


Solution 2-:   Time->O(n*n)    Space ->O(1)

Steps-:
1)By clearly visualizing 
2) First we have to transpose the given matrix
3)Then reverse every row 
4)At last we achive our goal


Code-:

void transpose(vector<vector<int>>&matrix)
    {
      int n=matrix.size();
      for(int i=0;i<n;i++)
      {
        for(int j=i;j<n;j++)
        {
           swap(matrix[i][j],matrix[j][i]);
        }
     }
    }
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        //transpose
        transpose(matrix);
        
        //reverse every row
        for(int i=0;i<n;i++)
        {
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
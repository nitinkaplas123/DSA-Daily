question link-:
https://leetcode.com/problems/spiral-matrix-ii/description/

Steps-:
1)Here we give number n eg. n=3 then we have to make a 2d matrix 3*3 where we have to fill the value 1 to n 
  in spiral order after that return that 2d matrix.
2)Just make changes in spiral order 1 question.
3)Just store the value in that index i,j.



Code-:

vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>ans( n , vector<int> (n));
        int top=0,bottom=n-1;
        int left=0,right=n-1;
        int val=1;
        while(top<=bottom && left<=right)
        {
            //left to right
            for(int i=left;i<=right;i++)
            {
                ans[top][i]=val++;
                // ans.push_back(matrix[top][i]);
            }
            top++;

            //top to bottom
            for(int i=top;i<=bottom;i++)
            {
                ans[i][right]=val++;
              //  ans.push_back(matrix[i][right]);
            }
            right--;

            //right to left
            if(top<=bottom)
            {
               for(int i=right;i>=left;i--)
               {
                ans[bottom][i]=val++;
                //ans.push_back(matrix[bottom][i]);
               }
               bottom--;
            }
            

            //bottom to top
            if(left<=right)
            {
              for(int i=bottom;i>=top;i--)
              {
                ans[i][left]=val++;
                //ans.push_back(matrix[i][left]);
              }
              left++;
            }
        }
        return ans;
    }
Solution -:

Steps-> In notebook No. 1 Page No. 25 

Steps-:
1) In while loop we check top<=bottom and left<=right
2) Then we go to 1st (left to right) and fixing top (here top is just checked in a while condition).After
   top++ we have to check this in upcoming cases.
3) Then we go to 2nd (top to bottom) and fixing right (here right is just checked in a while condition).After
   right-- which means now upcoming cases we have to checke this right
4) Then we go to 3rd (right to left) ans fixing bottom.As we used bottom here we have to check if(top<=bottom)
    before running the loop.
5) Then we go to 4th (bottom to top) ans fixing left.As we used left here we have to check if(left<=right)
    before running the loop.


Code-:
vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>ans;
        int n=matrix.size();
        int m=matrix[0].size();
        int top=0,bottom=n-1;
        int left=0,right=m-1;

        while(top<=bottom && left<=right)
        {
            //left to right
            for(int i=left;i<=right;i++)
            {
                ans.push_back(matrix[top][i]);
            }
            top++;

            //top to bottom
            for(int i=top;i<=bottom;i++)
            {
                ans.push_back(matrix[i][right]);
            }
            right--;

            //right to left
            if(top<=bottom)
            {
               for(int i=right;i>=left;i--)
               {
                ans.push_back(matrix[bottom][i]);
               }
               bottom--;
            }
            

            //bottom to top
            if(left<=right)
            {
              for(int i=bottom;i>=top;i--)
              {
                ans.push_back(matrix[i][left]);
              }
              left++;
            }
        }
        return ans;
    }
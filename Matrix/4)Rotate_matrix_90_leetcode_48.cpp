Solution1-:
1)Just visualize the pattern and  store into dummy vector of vcetor.
 
Code-:  Time Complexity->O(n*n)   Space ->O(n*n)
 void rotate(vector<vector<int>>& matrix) {
        vector<vector<int>>v;
        vector<int>v1;
        int n=matrix.size();
        for(int i=0;i<n;i++)
        {
            for(int j=n-1;j>=0;j--)
            {
                int val=matrix[j][i];
                v1.push_back(val);
            }
            v.push_back(v1);
            v1.clear();
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                matrix[i][j]=v[i][j];
            }
            cout<<endl;
        }
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





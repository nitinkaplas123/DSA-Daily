Solution 1-:
Steps-:
1)same as we do in anti traversal 
2)just have to change the second value in 3d vectors
3)here sum of index (row + col) are same for diagonal traversal.

eg 
   0 1 2 
 0[1,2,3]  [0+0,0+1,0+2]   [0,1,2]       here we see 0 are 1st diagonal.
 1[4,5,6]  [1+0,1+1,1+2]   [1,2,3]       1 are second diagonal.
 2[7,8,9]  [2+0,2+1,2+2]   [2,3,4]       2 are third diagonal. 3 and 4 so on.

 o/p=> {1},{4,2},{7,5,3},{8,6},{9}

 here sum of indexed are equal.


Code-: Time->O(N*M) Space->O(N*M)
vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<int>ans;
        vector<vector<int>>v;

        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            int m=nums[i].size();
            for(int j=0;j<m;j++)
            {
                int index=i+j;
                v.push_back({index,j,nums[i][j]});
            }
        }

        sort(v.begin(),v.end());

        for(int i=0;i<v.size();i++)
        {
           ans.push_back(v[i][2]);
        }
        return ans;
    }




Solution 2-:
Steps-:
1)Using level order traversal BFS 
2)In bfs we use queue


Code-:
vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<int>ans;
        queue<pair<int,int>>q;
        int n=nums.size();

        q.push({0,0});

        while(q.empty()==false)
        {
            int row=q.front().first;
            int col=q.front().second;
            q.pop();

            ans.push_back(nums[row][col]);

            if(col==0 and row+1<n)
            q.push({row+1,col});

            int m=nums[row].size();

            if(col+1<m )
            q.push({row,col+1}); 
        }
        return ans;
    }
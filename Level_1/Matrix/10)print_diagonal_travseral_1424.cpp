Solution 1-:
Steps-:
1)same as we do in anti traversal 
2)just have to change the second value in 3d vectors

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
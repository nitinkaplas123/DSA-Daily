Solution 1-:
Input:
N = 3
matrix[][] = 3 2 3
             4 5 1
             7 8 9
Output:
3 2 4 3 5 7 1 8 9

Steps-:
1)Here we make a 2d vector where we store three thing 
  {i+j,i,matrix[i][j]}

  eg.          0 1 2
  matrix[][] 0 3 2 3
             1 4 5 1
             2 7 8 9


  [{0,0,3},{1,0,2},{2,0,3}]
  [{1,1,4},{2,1,5},{3,1,1}]
  [{2,2,7},{3,2,8},{4,2,9}]


2) we are sorting this 
   why ?

   1.  for 0 
       if u clearly see there is only one starting with 0 => ans=>{3}
   2.  for 1 
       there is 2 values starting with 1 which is {1,0,2} and {1,1,4} but we need order {2,4}
       thats why we add 2 values as i 
       after sorting
       {1,0,2} ,{1,1,4}

       ans => {2,4}

    3. similarly for 2 


Code-: Time-> O(N*N)
vector<int> antiDiagonalPattern(vector<vector<int>> matrix) 
{
       int n=matrix.size();
       vector<int>ans;
       vector<vector<int>>v;
       for(int i=0;i<n;i++)
       {
           for(int j=0;j<n;j++)
           {
               int index=i+j;
               v.push_back({i+j,i,matrix[i][j]});
           }
       }
       
       sort(v.begin(),v.end());
       
       for(int i=0;i<v.size();i++)
       {
          ans.push_back(v[i][2]);
       }
       return ans;
}

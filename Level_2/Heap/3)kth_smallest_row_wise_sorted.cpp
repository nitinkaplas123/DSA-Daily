Question ->https://www.geeksforgeeks.org/problems/kth-element-in-matrix/1

Steps-:
1)similar to k_sorted_linked_list.


Solution 1-: Time->O(Klog(N))
int kthSmallest(int mat[MAX][MAX], int n, int k)
{
   priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
   
   for(int i=0;i<n;i++)
   {
       pq.push({mat[i][0],{i,0}});
   }
   
   for(int i=0;i<k-1;i++)
   {
       auto x=pq.top();
       pq.pop();
       
       int row=x.second.first;
       int col=x.second.second;
       
       if(col+1<n)
       pq.push({mat[row][col+1],{row,col+1}});
   }
   return pq.top().first;
}
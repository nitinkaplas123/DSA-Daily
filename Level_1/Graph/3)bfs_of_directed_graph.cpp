Question -> https://www.geeksforgeeks.org/problems/bfs-traversal-of-graph/1

Solution 1-:
Steps-:
1)Using same idea as for undirected graph.


Code-:
vector<int> bfsOfGraph(int V, vector<int> adj[]) {
       vector<int>ans;
       queue<int>q;
       q.push(0);
       vector<int>visited(V,false);
       visited[0]=true;
       while(q.empty()==false)
       {
           int val=q.front();
           q.pop();
           ans.push_back(val);
           
           for(auto x:adj[val])
           {
               if(visited[x]==false)
               {
                   visited[x]=true;
                   q.push(x);
               }
           }
       }
       return ans;
}
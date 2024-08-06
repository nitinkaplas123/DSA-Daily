Solution 1-:
Steps-:
1)Here we need shortest distance from source to every vertex.
2)So for shortest distance we do bfs because bfs goes from level to level
  and we get smallest distance using this.
3)Rest Code is same as of bfs.



Code-:
vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        vector<int>ans(N,INT_MAX);
        vector<int>adj[N];
        for(int i=0;i<M;i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v] .push_back(u);
        }
        
        ans[src]=0;
        queue<int>q;
        vector<int>visited(N,false);
        q.push(src);
        visited[src]=true;
        
        while(q.empty()==false)
        {
            int val=q.front();
            q.pop();
            
            for(auto x:adj[val])
            {
                if(visited[x]==false)
                {
                    visited[x]=true;
                    ans[x]=1+ans[val];
                    q.push(x);
                }
            }
        }
        
        for(int i=0;i<N;i++)
        {
            if(ans[i]==INT_MAX)
            ans[i]=-1;
        }
        return ans;
}
Question -> https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1

Solution 1-:
Steps-:
1)Same idea  going depth first.

Code-:
void dfs(vector<int>adj[],vector<int>&ans,int s,vector<int>&visited)
{
        visited[s]=true;
        ans.push_back(s);
        
        for(auto x:adj[s])
        {
            if(visited[x]==false)
            dfs(adj,ans,x,visited);
        }
}
vector<int> dfsOfGraph(int V, vector<int> adj[]) {
       vector<int>ans;
       vector<int>visited(V,false);
       dfs(adj,ans,0,visited);
       return ans;
}

Solution 1-:
Steps-:
1)using dfs 
2)here the graph may be of 2-3 breakage will be there.
3)visited[array] is used to check whelter paticipular is used or not as we used in undirected question.
4)reckracnce array is used to put the element update for current graph like 2nd part not 1st part.
4)now if we have 2 disconnected graph -:
  1st graph -> suppose there is no loop.
  so we make visited array same but rec[array]=false.


Code-:
bool dfs(vector<int>adj[],vector<int>&visited,int src,vector<int>&rec)
    {
        visited[src]=true;
        rec[src]=true;
        
        for(auto x:adj[src])
        {
            if(visited[x]==false and dfs(adj,visited,x,rec)==true)
            return true;
            else if(rec[x]==true)
            return true;
            else
            continue;
            
        }
        rec[src]=false;
        return false;
        
     }
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int>visited(V,false);
        vector<int>rec(V,false);
        for(int i=0;i<V;i++)
        {
            if(visited[i]==false)
            {
                if(dfs(adj,visited,i,rec)==true)
                return true;
            }
        }
        return false;
    }
  
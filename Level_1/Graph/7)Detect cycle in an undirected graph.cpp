Solution 1-:
Steps-:
1)here we use dfs and visited array to mark which is used.
2)here we use prev variable and src varible which tells us that src value ka prev value kya ha.
3)if we get prev value!=x (which is (adjacency)value of src) and visited[x]==true 
  it means there is a cycle because x is repeating element.

Code-: Time->O(V+E)
bool dfs(vector<int>adj[],vector<int>&visited,int s,int &prev)
    {
        visited[s]=true;
        
        for(auto x:adj[s])
        {
            if(visited[x]==false)
            {
                if(dfs(adj,visited,x,s)==true)
                return true;
            }
            else if(visited[x]==true and x!=prev)
            return true;
            else
            continue;
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
       vector<int>visited(V,false);
       int prev=-1;
       for(int i=0;i<V;i++)
       {
           if(visited[i]==false)
           if(dfs(adj,visited,i,prev)==true)
           return true;
       }
       return false;
    }
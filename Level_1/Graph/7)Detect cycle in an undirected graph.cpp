Solution 1-:
Steps-:
1)here we use dfs and visited array to mark which is used.
2)here we use prev variable and src varible which tells us that src value ka prev value kya ha.
3)if we get prev value!=x (which is (adjacency)value of src) and visited[x]==true 
  it means there is a cycle because x is repeating element.


Code-: Time->O(V+E)
bool dfs(vector<int>adj[],int &prev,vector<int>&visited,int src)
    {
        visited[src]=true;
        
        for(auto x:adj[src])
        {
            if(x!=prev and visited[x]==false)
            {
                if(dfs(adj,src,visited,x)==true)
                return true;
            }
            else if(x!=prev and visited[x]==true)
            return 1;
            else
            continue;
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        int back=-1;
        vector<int>visited(V,false);
        for(int i=0;i<V;i++)
        {
            if(visited[i]==false)
            {
                 int res=dfs(adj,back,visited,i);
                 if(res==1)
                 return 1;
            }
        }
        return 0;
    }
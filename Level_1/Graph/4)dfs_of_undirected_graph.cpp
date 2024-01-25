Solution 1-:
Steps-:
1)dfs means going depth of current source.


Code-:
#include <bits/stdc++.h>
using namespace std;
void addEdge(vector<int>adj[],int u,int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
vector<int>ans;
void dfs(vector<int>adj[],vector<int>&visited,int s)
{
   visited[s]=true;
   ans.push_back(s);
   
   for(auto x:adj[s])
   {
       if(visited[x]==false)
       dfs(adj,visited,x);
   }
}

void helper(vector<int>adj[],int V)
{
    vector<int>visited(V,false);
    int s=0;
    dfs(adj,visited,s);
    
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
}

int main() 
{
	int V=7;
	vector<int>adj[V];
	addEdge(adj,0,1);
	addEdge(adj,0,4);
	addEdge(adj,1,2);
	addEdge(adj,2,3);
	addEdge(adj,4,5);
	addEdge(adj,4,6);
	helper(adj,V);
}


Question 2-: Dfs of disconnected graph with no source.

Solution 1-:
Steps-:
1)Same approach as we do in bfs for disconnected graph.

Code-:
#include <bits/stdc++.h>
using namespace std;
void addEdge(vector<int>adj[],int u,int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
vector<int>ans;
void dfs(vector<int>adj[],vector<int>&visited,int s)
{
   visited[s]=true;
   ans.push_back(s);
   
   for(auto x:adj[s])
   {
       if(visited[x]==false)
       dfs(adj,visited,x);
   }
}

void helper(vector<int>adj[],int V)
{
    vector<int>visited(V,false);
    for(int i=0;i<V;i++)
    {
        if(visited[i]==false)
        dfs(adj,visited,i);
    }
    
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
}

int main() 
{
	int V=5;
	vector<int>adj[V];
	addEdge(adj,0,1);
	addEdge(adj,0,2);
	addEdge(adj,1,2);
	addEdge(adj,3,4);
	
	helper(adj,V);
}
Solution 1-:
Steps-:
1)Here we have to traverse the given undirected graph in bfs.
2)bFS means level order traversal.
3)As we know for bfs we use queue data struture here also we are using the same.
4)We know in unidirected graph we have multiple value of same because both are unidircted 
  for this problem we make -:
  visited[array] 
5)by traversing the value which are put into answer make that visited[value]=true so that in future we 
  cannot using this value.


Code-: Time->O(V+E)
#include <bits/stdc++.h>
using namespace std;
void addEdge(vector<int>adj[],int u,int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void helper(vector<int>adj[],int V)
{
    vector<int>visited(V,false);
    vector<int>ans;
    queue<int>q;
    q.push(0);
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
    
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
}

int main() 
{
	int V=6;
	vector<int>adj[V];
	addEdge(adj,0,1);
	addEdge(adj,0,2);
	addEdge(adj,0,5);
	addEdge(adj,1,3);
	addEdge(adj,3,5);
	addEdge(adj,5,4);
	addEdge(adj,2,4);
	helper(adj,V);
}



2. 
When the graph are disconnected and source is not given

Solution 2-:
#include <bits/stdc++.h>
using namespace std;
void addEdge(vector<int>adj[],int u,int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
vector<int>ans;
void solve(vector<int>adj[],vector<int>&visited,int s)
{
    
    queue<int>q;
    q.push(s);
    visited[s]=true;
    
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

}

void helper(vector<int>adj[],int V)
{
    vector<int>visited(V,false);
    for(int i=0;i<V;i++)
    {
        if(visited[i]==false)
        {
            solve(adj,visited,i);
        }
    }
    
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
	addEdge(adj,0,2);
	addEdge(adj,2,3);
	addEdge(adj,1,3);
	addEdge(adj,4,5);
	addEdge(adj,4,6);
	helper(adj,V);
}
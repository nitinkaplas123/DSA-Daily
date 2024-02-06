Question -> https://www.geeksforgeeks.org/problems/print-adjacency-list-1587115620/1

Solution 1-:
Steps-:
1)Make a vector of size V.
2)Now if its a unidirected graph then we have to copy all the elements into vector adj[V].
3)Now traverse the adj vector list and print all the values accordingly.


Code-: Time-> O(V+2*E)  Space->O(V+2*E)
 vector<vector<int>> printGraph(int V, vector<pair<int,int>>edges) 
    {
       vector<vector<int>>v;
       vector<int>adj[V];
       int n=edges.size();
       
       for(int i=0;i<n;i++)
       {
           int u=edges[i].first;
           int v=edges[i].second;
           adj[u].push_back(v);
           adj[v].push_back(u);
       }
       
       for(int i=0;i<V;i++)
       {
           vector<int>v1;
           for(auto x:adj[i])
           {
               v1.push_back(x);
           }
           v.push_back(v1);
       }
       return v;
    }
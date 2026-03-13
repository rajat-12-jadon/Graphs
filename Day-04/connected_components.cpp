#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void dfs(int node, vector<bool>& vis, vector<vector<int>>& adj, vector<int>& component)
    {
        vis[node] = true;
        component.push_back(node);
        
        for(int i = 0; i < adj[node].size(); i++)
        {
            int nbr = adj[node][i];
            if(vis[nbr] == false)
            {
                dfs(nbr, vis, adj, component);
            }
        }
    }
    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
        
        // code here
        vector<vector<int>> adj(V);
        
        for(int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<vector<int>> res;
        vector<bool> vis(V, false);
        for(int i = 0; i < V; i++)
        {
            if(vis[i] == false)
            {
                vector<int> component;
                
                dfs(i, vis, adj, component);
                res.push_back(component);
            }
        }
        return res;
    }
};

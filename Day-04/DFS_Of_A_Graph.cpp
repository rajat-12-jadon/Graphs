#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    void dfs(int start, vector<bool>& vis, vector<int>& result, vector<vector<int>>& adj)
    {
        vis[start] = 1;
        result.push_back(start);
        
        for(int nbr : adj[start])
        {
            if(vis[nbr] == 0)
            {
                dfs(nbr, vis, result, adj);
            }
        }
    }
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        int n = adj.size();
        vector<bool> vis(n, 0);
        
        vector<int> result;
        
        dfs(0, vis, result, adj);
        
        return result;
    }
};
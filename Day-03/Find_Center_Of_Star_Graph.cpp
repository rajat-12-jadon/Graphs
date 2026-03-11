// LeetCode 1791

// Find Center of Star Graph

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int V = edges.size() + 1;

        vector<vector<int>> adj(V + 1);

        for(int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for(int i = 1; i <= V; i++)
        {
            if(adj[i].size() == V - 1)
            {
                return i;
            }
        }

        return -1;
    }
};
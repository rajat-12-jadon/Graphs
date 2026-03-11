// LeetCode 1971

// Find Path if Exists in Graph

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void bfs(int source, vector<vector<int>>& adj, vector<int>& visited)
    {
        queue<int> q;
        q.push(source);
        visited[source] = true;

        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            for(int j = 0; j < adj[node].size(); j++)
            {
                int nbr = adj[node][j];
                if(!visited[nbr])
                {
                    visited[nbr] = true;
                    q.push(nbr);
                }
            }
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);

        for(int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> visited(n, false);
        bfs(source, adj, visited);

        return visited[destination];
    }
};
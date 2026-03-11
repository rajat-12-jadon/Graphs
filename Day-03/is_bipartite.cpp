#include <bits/stdc++.h>
using namespace std; 

class Solution {
public:
    bool bfs(int start, vector<vector<int>>& graph, vector<int>& color)
    {
        queue<int> q;
        q.push(start);
        color[start] = 0;

        while(!q.empty())
        {
            int node = q.front();
            q.pop();

            for(int i = 0; i < graph[node].size(); i++)
            {
                int neigh = graph[node][i];

                if(color[neigh] == -1)
                {
                    color[neigh] = 1 - color[node];
                    q.push(neigh);
                }
                else if(color[neigh] == color[node])
                {
                    return false;
                }
            }
        }

        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> color(V, -1);

        for(int i = 0; i < V; i++)
        {
            if(color[i] == -1)
            {
                if(!bfs(i, graph, color))
                    return false;
            }
        }

        return true;
    }
};
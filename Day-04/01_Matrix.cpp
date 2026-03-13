#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void bfs(queue<pair<int,int>> &q, vector<vector<int>> &dist, vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        while(!q.empty())
        {
            auto node = q.front();
            q.pop();

            int r = node.first;
            int c = node.second;

            // down
            if(r+1 < n && dist[r+1][c] == -1)
            {
                dist[r+1][c] = dist[r][c] + 1;
                q.push({r+1, c});
            }

            // up
            if(r-1 >= 0 && dist[r-1][c] == -1)
            {
                dist[r-1][c] = dist[r][c] + 1;
                q.push({r-1, c});
            }

            // right
            if(c+1 < m && dist[r][c+1] == -1)
            {
                dist[r][c+1] = dist[r][c] + 1;
                q.push({r, c+1});
            }

            // left
            if(c-1 >= 0 && dist[r][c-1] == -1)
            {
                dist[r][c-1] = dist[r][c] + 1;
                q.push({r, c-1});
            }
        }
    }
    vector<vector<int>> nearest(vector<vector<int>>& grid) {
        // code here
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dist(n, vector<int>(m, -1));
        queue<pair<int,int>> q;

        // Push all cells containing 1 into queue
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == 1)
                {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        bfs(q, dist, grid);

        return dist;
    }
};
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void bfs(queue<pair<int,int>>& q, vector<vector<int>>& dist)
    {
        int n = dist.size();
        int m = dist[0].size();

        while(!q.empty())
        {
            auto node = q.front();
            q.pop();

            int r = node.first;
            int c = node.second;

            // up
            if(r - 1 >= 0 && dist[r-1][c] == -1)
            {
                dist[r-1][c] = dist[r][c] + 1;
                q.push({r-1, c});
            }

            // down
            if(r + 1 < n && dist[r+1][c] == -1)
            {
                dist[r+1][c] = dist[r][c] + 1;
                q.push({r+1, c});
            }

            // left
            if(c - 1 >= 0 && dist[r][c-1] == -1)
            {
                dist[r][c-1] = dist[r][c] + 1;
                q.push({r, c-1});
            }

            // right
            if(c + 1 < m && dist[r][c+1] == -1)
            {
                dist[r][c+1] = dist[r][c] + 1;
                q.push({r, c+1});
            }
        }
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> dist(n, vector<int>(m, -1));
        queue<pair<int,int>> q;

        // push all 0 cells
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(mat[i][j] == 0)
                {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        bfs(q, dist);

        return dist;
    }
};
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void bfs(queue<pair<pair<int,int>, int>>& q, vector<vector<int>>& vis,
             vector<vector<int>>& mat, int &t)
    {
        int n = mat.size();
        int m = mat[0].size();

        while(!q.empty())
        {
            auto node = q.front();
            q.pop();

            int r = node.first.first;
            int c = node.first.second;
            int tm = node.second;

            t = max(t, tm);

            // down
            if(r+1 < n && mat[r+1][c] == 1 && vis[r+1][c] == 0)
            {
                q.push({{r+1,c}, tm+1});
                vis[r+1][c] = 2;
            }

            // up
            if(r-1 >= 0 && mat[r-1][c] == 1 && vis[r-1][c] == 0)
            {
                q.push({{r-1,c}, tm+1});
                vis[r-1][c] = 2;
            }

            // right
            if(c+1 < m && mat[r][c+1] == 1 && vis[r][c+1] == 0)
            {
                q.push({{r,c+1}, tm+1});
                vis[r][c+1] = 2;
            }

            // left
            if(c-1 >= 0 && mat[r][c-1] == 1 && vis[r][c-1] == 0)
            {
                q.push({{r,c-1}, tm+1});
                vis[r][c-1] = 2;
            }
        }
    }
    int orangesRot(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> vis(n, vector<int>(m,0));
        queue<pair<pair<int,int>, int>> q;

        // push all rotten oranges first
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==2)
                {
                    q.push({{i,j},0});
                    vis[i][j]=2;
                }
            }
        }

        int t = 0;

        bfs(q, vis, mat, t);
        
        // check fresh oranges left
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==1 && vis[i][j]!=2)
                return -1;
            }
        }

        return t;
    }
};
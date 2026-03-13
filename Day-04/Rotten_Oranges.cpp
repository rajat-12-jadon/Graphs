#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void dfs(int r, int c, int time, vector<vector<int>>& mat, vector<vector<int>>& t)
    {
        int n = mat.size();
        int m = mat[0].size();

        // Boundary check
        if(r < 0 || c < 0 || r >= n || c >= m)
            return;

        // If cell is empty (0), rot cannot spread
        if(mat[r][c] == 0)
            return;

        // If we have already reached this cell earlier
        // with a smaller or equal time, stop recursion
        if(time >= t[r][c])
            return;

        // Update the minimum time to rot this orange
        t[r][c] = time;

        // Spread rot in all 4 directions
        dfs(r+1, c, time+1, mat, t); // down
        dfs(r-1, c, time+1, mat, t); // up
        dfs(r, c+1, time+1, mat, t); // right
        dfs(r, c-1, time+1, mat, t); // left
    }
    int orangesRot(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();
        int m = mat[0].size();

        // Time matrix to store the minimum time
        // each orange becomes rotten
        vector<vector<int>> t(n, vector<int>(m, INT_MAX));

        // Start DFS from every initially rotten orange
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(mat[i][j] == 2)
                {
                    dfs(i, j, 0, mat, t);
                }
            }
        }

        int ans = 0;

        // Check if any fresh orange is unreachable
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                // If fresh orange never got rotten
                if(mat[i][j] == 1)
                {
                    if(t[i][j] == INT_MAX)
                        return -1;

                    // Track maximum time taken
                    ans = max(ans, t[i][j]);
                }
            }
        }

        return ans;
    }
};
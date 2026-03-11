#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void bfs(int i, int j, vector<vector<char>>& grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        q.push({i, j});
        grid[i][j] = '#'; // we found O, but if it becomes X or not, depends on condition

        while(!q.empty())
        {
            auto node = q.front();
            q.pop();

            int r = node.first;
            int c = node.second;
            
            // down
            if(r+1 < n && grid[r+1][c] == 'O')
            {
                q.push({r+1, c});
                grid[r+1][c] = '#';
            }
            // up
            if(r-1 >= 0 && grid[r-1][c] == 'O')
            {
                q.push({r-1, c});
                grid[r-1][c] = '#';
            }
            // right
            if(c+1 < m && grid[r][c+1] == 'O')
            {
                q.push({r, c+1});
                grid[r][c+1] = '#';
            }
            // left
            if(c-1 >= 0 && grid[r][c-1] == 'O')
            {
                q.push({r, c-1});
                grid[r][c-1] = '#';
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        // boundary rows
        for(int j = 0; j < m; j++)
        {
            if(board[0][j] == 'O') bfs(0, j, board);
            if(board[n-1][j] == 'O') bfs(n-1, j, board);
        }

        // boundary columns
        for(int i = 0; i < n; i++)
        {
            if(board[i][0] == 'O') bfs(i, 0, board);
            if(board[i][m-1] == 'O') bfs(i, m-1, board);
        }

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(board[i][j] == 'O')
                    board[i][j] = 'X';
                else if(board[i][j] == '#')
                    board[i][j] = 'O';
            }
        }
    }
};
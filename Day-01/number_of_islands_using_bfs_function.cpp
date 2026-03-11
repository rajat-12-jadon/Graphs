#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void bfs(int row, int col, vector<vector<char>>& grid)
    {
        queue<pair<int, int>> q;
        q.push({row, col});
        grid[row][col] = 'W';

        int n = grid.size();
        int m = grid[0].size();

        while(!q.empty())
        {
            auto node = q.front();
            q.pop();
            int r = node.first;
            int c = node.second;
            // down
            if(r+1 < n && grid[r+1][c] == 'L')
            {
                q.push({r+1, c});
                grid[r+1][c] = 'W';
            }
            // up
            if(r-1 >= 0 && grid[r-1][c] == 'L')
            {
                q.push({r-1, c});
                grid[r-1][c] = 'W';
            }
            // right
            if(c+1 < m && grid[r][c+1] == 'L')
            {
                q.push({r, c+1});
                grid[r][c+1] = 'W';
            }
            // left
            if(c-1 >= 0 && grid[r][c-1] == 'L')
            {
                q.push({r, c-1});
                grid[r][c-1] = 'W';
            }
            // top-left
            if(r-1 >= 0 && c-1 >= 0 && grid[r-1][c-1] == 'L')
            {
                q.push({r-1,c-1});
                grid[r-1][c-1] = 'W';
            }
            // top-right
            if(r-1 >= 0 && c+1 < m && grid[r-1][c+1] == 'L')
            {
                q.push({r-1,c+1});
                grid[r-1][c+1] = 'W';
            }
            // bottom-left
            if(r+1 < n && c-1 >= 0 && grid[r+1][c-1] == 'L')
            {
                q.push({r+1,c-1});
                grid[r+1][c-1] = 'W';
            }
            // bottom-right
            if(r+1 < n && c+1 < m && grid[r+1][c+1] == 'L')
            {
                q.push({r+1,c+1});
                grid[r+1][c+1] = 'W';
            }
            
        }
    }

    int countIslands(vector<vector<char>>& grid)
    {
        int islands = 0;

        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[0].size(); j++)
            {
                if(grid[i][j] == 'L')
                {
                    islands++;
                    bfs(i, j, grid);
                }
            }
        }

        return islands;
    }
};
int main()
{
    int n, m;
    cout << "Enter rows and columns: ";
    cin >> n >> m;

    vector<vector<char>> grid(n, vector<char>(m));

    cout << "Enter grid values (L for land, W for water):\n";

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }

    Solution obj;
    int result = obj.countIslands(grid);

    cout << "Number of Islands: " << result << endl;

    return 0;
}
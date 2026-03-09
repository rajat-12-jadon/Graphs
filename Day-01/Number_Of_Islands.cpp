#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int countIslands(vector<vector<char>>& grid) {
        
        int islands = 0;
        queue<pair<int, int>> q;

        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[i].size(); j++)
            {
                if(grid[i][j] == 'L')
                {
                    islands++;
                    grid[i][j] = 'W';
                    q.push({i, j});

                    while(!q.empty())
                    {
                        auto node = q.front();
                        q.pop();

                        int r = node.first;
                        int c = node.second;

                        // down
                        if(r+1 < grid.size() && grid[r+1][c] == 'L')
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
                        if(c+1 < grid[0].size() && grid[r][c+1] == 'L')
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
                        if(r-1 >= 0 && c+1 < grid[0].size() && grid[r-1][c+1] == 'L')
                        {
                            q.push({r-1,c+1});
                            grid[r-1][c+1] = 'W';
                        }

                        // bottom-left
                        if(r+1 < grid.size() && c-1 >= 0 && grid[r+1][c-1] == 'L')
                        {
                            q.push({r+1,c-1});
                            grid[r+1][c-1] = 'W';
                        }

                        // bottom-right
                        if(r+1 < grid.size() && c+1 < grid[0].size() && grid[r+1][c+1] == 'L')
                        {
                            q.push({r+1,c+1});
                            grid[r+1][c+1] = 'W';
                        }
                    }
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
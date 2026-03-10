#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);

    for(int i = 0; i < n; i++)
    {
        cin >> grid[i];
    }

    int rooms = 0;
    queue<pair<int, int>> q;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(grid[i][j] == '.')
            {
                rooms++;
                grid[i][j] = '#';
                q.push({i, j});
                while(!q.empty())
                {
                    auto node = q.front();
                    q.pop();
                    int r = node.first;
                    int c = node.second;
                    // down
                    if(r+1 < n && grid[r+1][c] == '.')
                    {
                        q.push({r+1, c});
                        grid[r+1][c] = '#';
                    }
                    // up
                    if(r-1 >= 0 && grid[r-1][c] == '.')
                    {
                        q.push({r-1, c});
                        grid[r-1][c] = '#';
                    }
                    // right
                    if(c+1 < m && grid[r][c+1] == '.')
                    {
                        q.push({r, c+1});
                        grid[r][c+1] = '#';
                    }
                    // left
                    if(c-1 >= 0 && grid[r][c-1] == '.')
                    {
                        q.push({r, c-1});
                        grid[r][c-1] = '#';
                    }
                }
            }
        }
    }
    cout << rooms;

    return 0;
}
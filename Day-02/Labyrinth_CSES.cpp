#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<string> grid(n);

    // read grid
    for(int i = 0; i < n; i++)
    {
        cin >> grid[i];
    }

    queue<pair<int,int>> q;

    // store direction used to reach each cell
    vector<vector<char>> dir(n, vector<char>(m));

    int sr = 0;
    int sc = 0;

    // find starting position A
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(grid[i][j] == 'A')
            {
                sr = i;
                sc = j;
            }
        }
    }

    // push A into queue
    q.push({sr, sc});

    // mark A as visited
    grid[sr][sc] = '#';

    // store B position when found
    int er = -1, ec = -1;

    // BFS traversal
    while(!q.empty())
    {
        auto node = q.front();
        q.pop();

        int r = node.first;
        int c = node.second;

        // if B reached
        if(grid[r][c] == 'B')
        {
            er = r;
            ec = c;
            break;
        }

        // move DOWN
        if(r+1 < n && (grid[r+1][c] == '.' || grid[r+1][c] == 'B'))
        {
            q.push({r+1, c});
            dir[r+1][c] = 'D';

            if(grid[r+1][c] == '.')
                grid[r+1][c] = '#';
        }

        // move UP
        if(r-1 >= 0 && (grid[r-1][c] == '.' || grid[r-1][c] == 'B'))
        {
            q.push({r-1, c});
            dir[r-1][c] = 'U';

            if(grid[r-1][c] == '.')
                grid[r-1][c] = '#';
        }

        // move RIGHT
        if(c+1 < m && (grid[r][c+1] == '.' || grid[r][c+1] == 'B'))
        {
            q.push({r, c+1});
            dir[r][c+1] = 'R';

            if(grid[r][c+1] == '.')
                grid[r][c+1] = '#';
        }

        // move LEFT
        if(c-1 >= 0 && (grid[r][c-1] == '.' || grid[r][c-1] == 'B'))
        {
            q.push({r, c-1});
            dir[r][c-1] = 'L';

            if(grid[r][c-1] == '.')
                grid[r][c-1] = '#';
        }
    }

    // if B was not reached
    if(er == -1)
    {
        cout << "NO";
        return 0;
    }

    // reconstruct path
    string path;

    int r = er, c = ec;

    // go backwards until reaching A
    while(r != sr || c != sc)
    {
        char d = dir[r][c];
        path.push_back(d);

        // move opposite direction
        if(d == 'U') r++;
        else if(d == 'D') r--;
        else if(d == 'L') c++;
        else if(d == 'R') c--;
    }

    // reverse path because we built it from B → A
    reverse(path.begin(), path.end());

    cout << "YES\n";
    cout << path.size() << "\n";
    cout << path;

    return 0;
}
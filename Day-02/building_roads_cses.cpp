#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    // adjacency list
    vector<vector<int>> adj(n+1);

    // read roads
    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;

        // undirected graph
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<bool> visited(n+1, false);

    vector<int> rep;   // store one city per component

    for(int i = 1; i <= n; i++)
    {
        if(!visited[i])
        {
            rep.push_back(i);

            queue<int> q;
            q.push(i);
            visited[i] = true;

            while(!q.empty())
            {
                int node = q.front();
                q.pop();

                for(int j = 0; j < (int)adj[node].size(); j++)
                {
                    int nbr = adj[node][j];

                    if(!visited[nbr])
                    {
                        visited[nbr] = true;
                        q.push(nbr);
                    }
                }
            }
        }
    }
    cout << rep.size() - 1 << endl;
    int p = rep.size();
    for(int i = 1; i < p; i++)
    {
        cout << rep[i-1] << " " << rep[i] << endl;
    }

    return 0;
}
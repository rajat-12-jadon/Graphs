/*
    Question -> You hav a graph which has 5 vertices and 4 edges and an array edges[][] = [[0, 1], [1, 2], [2, 3], [1, 3]].
    You have to solve:
        (i). Print Adjacency Matrix
        (ii). Print Adjacency List and print all connected components
        (iii). Count the number of connected components
        (iv). Return any two indices which are not in same connected components group
        (v). Perform BFS on a graph
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int V, E;
    cin >> V >> E;

    vector<vector<int>> edges;

    for(int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
    }

    // -------------------------
    // (i) Adjacency Matrix
    // -------------------------

    vector<vector<int>> adjMat(V, vector<int>(V, 0));

    for(int i = 0; i < edges.size(); i++)
    {
        int row = edges[i][0];
        int col = edges[i][1];

        adjMat[row][col] = 1;
        adjMat[col][row] = 1;
    }

    cout << "Adjacency Matrix :" << endl;

    for(int i = 0; i < V; i++)
    {
        for(int j = 0; j < V; j++)
        {
            cout << adjMat[i][j] << " ";
        }
        cout << endl;
    }

    // -------------------------
    // (ii) Adjacency List
    // -------------------------

    vector<vector<int>> adj(V);

    for(int i = 0; i < E; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout << "\nAdjacency List :" << endl;

    for(int i = 0; i < V; i++)
    {
        cout << i << " -> ";
        for(int j = 0; j < adj[i].size(); j++)
        {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }

    // -------------------------
    // BFS traversal when source node is known
    // -------------------------

    vector<int> result;
    queue<int> q;
    vector<bool> visited(V, false);

    q.push(0);
    visited[0] = true;

    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        result.push_back(node);

        for(int i = 0; i < adj[node].size(); i++)
        {
            int nbr = adj[node][i];
            if(!visited[nbr])
            {
                visited[nbr] = true;
                q.push(nbr);
            }
        }
    }

    cout << "\nBFS Traversal from source node :" << endl;

    for(int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }

    // -------------------------
    // (v) BFS traversal of whole graph
    // -------------------------

    fill(visited.begin(), visited.end(), false);
    vector<int> result1;

    for(int i = 0; i < V; i++)
    {
        if(!visited[i])
        {
            queue<int> q;
            q.push(i);
            visited[i] = true;

            while(!q.empty())
            {
                int node = q.front();
                q.pop();

                result1.push_back(node);

                for(int j = 0; j < adj[node].size(); j++)
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

    cout << "\nBFS Traversal of whole graph :" << endl;

    for(int i = 0; i < result1.size(); i++)
    {
        cout << result1[i] << " ";
    }

    // -------------------------
    // Connected Components
    // -------------------------

    fill(visited.begin(), visited.end(), false);

    vector<vector<int>> ans;

    for(int i = 0; i < V; i++)
    {
        if(!visited[i])
        {
            vector<int> res;
            queue<int> q;

            q.push(i);
            visited[i] = true;

            while(!q.empty())
            {
                int node = q.front();
                q.pop();

                res.push_back(node);

                for(int j = 0; j < adj[node].size(); j++)
                {
                    int nbr = adj[node][j];

                    if(!visited[nbr])
                    {
                        visited[nbr] = true;
                        q.push(nbr);
                    }
                }
            }

            ans.push_back(res);
        }
    }

    cout << "\n\nConnected Components :" << endl;

    for(int i = 0; i < ans.size(); i++)
    {
        for(int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    // -------------------------
    // (iii) Count components
    // -------------------------

    cout << "\nNumber of Connected Components : ";
    cout << ans.size() << endl;

    // -------------------------
    // Counting components using BFS only
    // -------------------------

    fill(visited.begin(), visited.end(), false);

    int components = 0;

    for(int i = 0; i < V; i++)
    {
        if(!visited[i])
        {
            components++;

            queue<int> q;
            q.push(i);
            visited[i] = true;

            while(!q.empty())
            {
                int node = q.front();
                q.pop();

                for(int j = 0; j < adj[node].size(); j++)
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

    cout << "Components counted using BFS only : " << components << endl;

    // -------------------------
    // (iv) Two vertices from different components
    // -------------------------

    if(ans.size() >= 2)
    {
        int a = ans[0][0];
        int b = ans[1][0];

        cout << "\nTwo vertices in different components : ";
        cout << a << " " << b << endl;
    }

    return 0;
}
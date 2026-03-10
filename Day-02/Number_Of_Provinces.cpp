#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int provinces = 0;

        vector<bool> visited(n, false);

        for(int i = 0; i < n; i++)
        {
            if(!visited[i])
            {
                provinces++;

                queue<int> q;
                q.push(i);
                visited[i] = true;

                while(!q.empty())
                {
                    int node = q.front();
                    q.pop();

                    for(int j = 0; j < n; j++)
                    {
                        if(isConnected[node][j] == 1 && !visited[j])
                        {
                            visited[j] = true;
                            q.push(j);
                        }
                    }
                }
            }
        }

        return provinces;
    }
};

int main()
{
    int n;
    cout << "Enter number of cities: ";
    cin >> n;

    vector<vector<int>> isConnected(n, vector<int>(n));

    cout << "Enter adjacency matrix:\n";

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> isConnected[i][j];
        }
    }

    Solution obj;

    int result = obj.findCircleNum(isConnected);

    cout << "Number of Provinces: " << result << endl;

    return 0;
}
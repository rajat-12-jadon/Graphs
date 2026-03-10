#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {

        int n = rooms.size();
        vector<bool> visited(n, false);

        queue<int> q;
        q.push(0);
        visited[0] = true;

        while(!q.empty())
        {
            int node = q.front();
            q.pop();

            for(int i = 0; i < rooms[node].size(); i++)
            {
                int nbr = rooms[node][i];

                if(!visited[nbr])
                {
                    visited[nbr] = true;
                    q.push(nbr);
                }
            }
        }

        for(int i = 0; i < n; i++)
        {
            if(!visited[i])
                return false;
        }

        return true;
    }
};

int main()
{
    int n;
    cout << "Enter number of rooms: ";
    cin >> n;

    vector<vector<int>> rooms(n);

    cout << "Enter number of keys in each room followed by the keys:\n";

    for(int i = 0; i < n; i++)
    {
        int k;
        cout << "Room " << i << " keys count: ";
        cin >> k;

        rooms[i].resize(k);

        for(int j = 0; j < k; j++)
        {
            cin >> rooms[i][j];
        }
    }

    Solution obj;

    bool result = obj.canVisitAllRooms(rooms);

    if(result)
        cout << "All rooms can be visited\n";
    else
        cout << "All rooms cannot be visited\n";

    return 0;
}
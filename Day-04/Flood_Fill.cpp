#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int row, int col, vector<vector<int>>& image, int initial, int color)
    {
        int n = image.size();
        int m = image[0].size();

        image[row][col] = color;

        // up
        if(row-1 >= 0 && image[row-1][col] == initial)
            dfs(row-1, col, image, initial, color);

        // down
        if(row+1 < n && image[row+1][col] == initial)
            dfs(row+1, col, image, initial, color);

        // left
        if(col-1 >= 0 && image[row][col-1] == initial)
            dfs(row, col-1, image, initial, color);

        // right
        if(col+1 < m && image[row][col+1] == initial)
            dfs(row, col+1, image, initial, color);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int initial = image[sr][sc];

        if(initial == color) return image;

        dfs(sr, sc, image, initial, color);

        return image;
    }
};
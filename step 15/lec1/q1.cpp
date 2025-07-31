#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> q;
        int fresh = 0, minutes = 0;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) q.push({i, j});
                if (grid[i][j] == 1) fresh++;
            }
        }
        
        vector<int> dir = {0, 1, 0, -1, 0};
        while (!q.empty() && fresh > 0) {
            int size = q.size();
            while (size--) {
                auto [x, y] = q.front(); q.pop();
                for (int d = 0; d < 4; d++) {
                    int nx = x + dir[d], ny = y + dir[d+1];
                    if (nx < 0 || ny < 0 || nx >= m || ny >= n || grid[nx][ny] != 1) continue;
                    grid[nx][ny] = 2;
                    fresh--;
                    q.push({nx, ny});
                }
            }
            minutes++;
        }
        return fresh == 0 ? minutes : -1;
    }
};

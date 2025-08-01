#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;

        vector<vector<int>> dirs = {{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
        queue<pair<int,int>> q;
        q.push({0,0});
        grid[0][0] = 1;

        int pathLen = 1;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto [r,c] = q.front();
                q.pop();
                if (r == n-1 && c == n-1) return pathLen;

                for (auto& d : dirs) {
                    int nr = r + d[0], nc = c + d[1];
                    if (nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 0) {
                        q.push({nr,nc});
                        grid[nr][nc] = 1;
                    }
                }
            }
            pathLen++;
        }
        return -1;
    }
};

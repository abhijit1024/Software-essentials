/*
    https://leetcode.com/problems/rotting-oranges/description/
    Time complexity - O(mn)
    Space complexity - O(mn)
*/
class Solution {
public:
    int maxRotTime(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        const int M = grid.size(), N = grid[0].size();
        for(int i = 0; i < M; i++) {
            for(int j = 0; j < N; j++) {
                if(grid[i][j] == 2) {
                    q.emplace(make_pair(i, j));

                    grid[i][j] = 0;
                }
            }
        }
        int n_level = q.size(), level = 0;
        vector<vector<int>> dirs = {{1,0}, {-1, 0},
                                    {0, 1}, {0, -1}};
        while(!q.empty()) {
            auto pos = q.front();
            q.pop();
            --n_level;
            for(auto dir: dirs) {
                int r = pos.first + dir[0];
                int c = pos.second + dir[1];
                if(r >= 0 && r < M && c >= 0 && c < N 
                    && grid[r][c] != 0) {
                        q.emplace(make_pair(r, c));
                        grid[r][c] = 0;
                    }
            }
            if(n_level == 0 && !q.empty()) {
                 ++level;
                 n_level = q.size();
            }
        }
        for(int i = 0; i < M; i++) {
            for(int j = 0; j < N; j++) {
                if(grid[i][j] == 1)
                    return -1;
            }
        }
        return level;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        return maxRotTime(grid);
    }
};
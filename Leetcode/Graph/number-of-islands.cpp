/*
    https://leetcode.com/problems/number-of-islands/description/
    Time complexity - O(N*M)
    Space complexity - O(N*M)
*/
/*
    DFS sol.
*/
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size(), col = grid[0].size();
        int islands = 0;
        for(int r = 0; r < grid.size(); r++) {
            for(int c = 0; c < grid[0].size(); c++) {
                if(grid[r][c] == '1'){
                    dfs(grid, r, c);
                    islands++;
                }
            }
        }
        return islands;
    }
    void dfs(vector<vector<char>>&grid, int r, int c) {
        if(r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size()
            || grid[r][c] == '0') {
                return ;
            }
        grid[r][c] = '0';
        for(int i = 0; i < grid.size(); i++) {
            dfs(grid, r + 1, c);
            dfs(grid, r, c + 1);
            dfs(grid, r - 1, c);
            dfs(grid, r, c - 1);
        }
    }
};
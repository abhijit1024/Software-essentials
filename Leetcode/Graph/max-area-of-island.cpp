/*
    https://leetcode.com/problems/max-area-of-island/
*/
/*
    DFS sol.
    Time complexity - O(MN)
    Space complexity - O(N)
*/
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        // To track the area
        int area = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == 1) {
                    // Compares the new area with the current area
                    area = max(area ,(dfs(grid, i, j )));
                }
            }
        }
        return area;
    }
    int dfs(vector<vector<int>>&grid, int r, int c) {
        if(r < 0 || r >= grid.size() ||
            c < 0 || c >= grid[0].size() ||
            grid[r][c] == 0) {
                return 0;
            }
        grid[r][c] = 0;
        // Return the area 
        return 1 +
        dfs(grid, r + 1, c) +
        dfs(grid, r, c + 1) +
        dfs(grid, r - 1, c) +
        dfs(grid, r, c - 1);
    }
};
/*
    Bfs sol
    Time complexity - O(NM)
    Space complexity - O(N)
*/
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        int area = 0;
        for(int i = 0; i < row; i++) { 
            for(int j = 0; j < col; j++) {
                if(grid[i][j] == 1) {
                    area = max(area,bfs(grid, i, j));
                }
            }
        }
        return area;
    }
    /*
    Distances (i+j)
    0 1 2 3 4 5
    1 2 3 4 5 6
    2 3 4 5 6 7
    3 4 5 6 7 8
    4 5 6 7 8 9
    5 6 7 8 9 10
    Space complexity in worst case in square will be O(n),because the max
    dist will be in diagonal (manhattan dist )
    */
    int bfs(vector<vector<int>>&grid, int r, int c) {
        //Initialize the queue
        queue<pair<int, int>> q;
        
        q.push({r, c});
        grid[r][c] = 0;
        
        int area = 1;
        
        //Initialize the direction
        vector<array<int, 2>> coords = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        while(!q.empty()) {
            auto node = q.front(); 
            q.pop();
            
            // int row = node.first, col = node.second;
            auto [row, col] = node;

            for(auto [dx, dy]: coords) {
                int newrow = row + dx;
                int newcol = col + dy;

                //check if node is within the boundary
                if(newrow >= 0 && newrow < grid.size() 
                    && newcol >= 0 && newcol < grid[0].size()
                    && grid[newrow][newcol] == 1) {
                        //mark the node as visited
                        grid[newrow][newcol] = 0;
                        q.push({newrow, newcol});
                        //increase the area
                        area++;
                    }
            }
        }
        return area;
    }
};
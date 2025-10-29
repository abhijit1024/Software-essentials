/*
    https://leetcode.com/problems/path-with-minimum-effort/description/
    Using Dijkstra
    Time complexity - 
    Space complexity -
*/
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        const int M = heights.size(), N = heights[0].size();
        vector<vector<int>> effort(M, vector<int>(N, INT_MAX));
        vector<vector<int>> direction {{0,1}, {1,0}, {0, -1}, {-1, 0}};

        auto comp = [&](const array<int, 3>&a, array<int, 3>&b) {
            return a[0] > b[0];
        };

        priority_queue<array<int, 3>, vector<array<int, 3>>, decltype(comp) > min_heap(comp);

        effort[0][0] = 0;
        min_heap.push({0, 0, 0});

        while(!min_heap.empty()) {
            auto[curr_effort, row, col] = min_heap.top();
            min_heap.pop();
            
            if(row == M - 1 && col == N - 1) {
                break;
            }
            if(curr_effort > effort[row][col]) {
                continue;
            }
            for(auto dir: direction) {
                int r = row + dir[0] , c = col + dir[1];
                if(r >= 0 && r < M && c >= 0 && c < N) {
                    int new_effort = max(curr_effort, abs(heights[row][col] - heights[r][c]));
                    if(new_effort < effort[r][c]) {
                        effort[r][c] = new_effort;
                        min_heap.push({new_effort, r, c});
                    }
                }
            }
        }
        return effort[M-1][N-1];
    }
};
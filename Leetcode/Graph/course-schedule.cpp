/*
    https://leetcode.com/problems/course-schedule/
    Time complexity - O(V + E)
    Space complexity - O(V + E)
*/
class Solution {
public:
    bool dfsCycle(int curr, vector<bool>& visited, vector<bool>& rec_stack, 
                            vector<vector<int>>&g) {
        visited[curr] = true;
        rec_stack[curr] = true;
        
        for(int i = 0; i < g[curr].size(); i++) {
            int next = g[curr][i];
            if(rec_stack[next]) 
                return true;
            if(dfsCycle(g[curr][i], visited, rec_stack, g))
                return true;
        }
        rec_stack[curr] = false;
        return false;
    }
    bool dfs(int numCourses, vector<vector<int>>& g) {
        vector<bool> visited(numCourses, false);

        vector<bool> rec_stack(numCourses, false);

        for(int i = 0; i < numCourses; i++) {
            if(!visited[i] && dfsCycle(i, visited, rec_stack, g)) {
                return false;
            }
        }
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> g(numCourses);

        for(auto& edge: prerequisites) {
            g[edge[0]].emplace_back(edge[1]);
        }
        return dfs(numCourses, g);
    }
};
/*
    https://neetcode.io/problems/valid-tree?list=neetcode150
    Time complexity - O(V + E)
    Space complexity - O(V + E)
*/
class Solution {
public:
    bool dfsCycle(int curr, int parent, vector<vector<int>>& graph, 
                    vector<bool>& visited) {
        visited[curr] = true;

        for(auto nei: graph[curr]) {
            //skip edge to parent
            if (nei == parent) continue;
            //cycle found
            if(visited[nei]) return false;
            if(!dfsCycle(nei, curr, graph, visited)) return false;
        }
        return true;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() != n -1 ) return false;
        // adjacency list
        vector<vector<int>> adj(n);
        for(auto& e: edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<bool> visited(n, false);
        //check cycle
        if(!dfsCycle(0, -1, adj, visited))
            return false;
        // check is all the node are connected
        for(bool v: visited) 
            if(!v) return false;
        return true;

    }
};

/*
    https://leetcode.com/problems/min-cost-to-connect-all-points/description/
    Time complexity - 
    Space complexity -
*/
/*
    Using kruskals
*/
class DSU {
public:
    vector<int> Parent, Size;
    DSU(int n) : Parent(n + 1), Size(n + 1, 1) {
        for(int i = 0; i <= n; i++) Parent[i] = i;
    }
    int find(int node) {
        if(Parent[node] != node) {
            Parent[node] = find(Parent[node]);
        }
        return Parent[node];
    }
    bool unionSets(int u, int v) {
        int pu = find(u), pv = find(v);
        if (pu == pv) return false;
        if (Size[pu] < Size[pv]) swap(pu, pv);
        Size[pu] += Size[pv];
        Parent[pv] = pu;
        return true;
    }
};
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
       int n = points.size();
       DSU dsu(n);
       vector<tuple<int, int, int>> edges;

       for(int i = 0; i < n; i++) {
        for(int j = i + 1; j  < n; j++) {
            int dist = abs(points[i][0] - points[j][0]) +
                        abs(points[i][1] - points[j][1]);
            edges.push_back({dist, i, j});
        }
       }
       sort(edges.begin(), edges.end());
       int res = 0;
       for(auto& [dist, u, v] : edges) {
        if(dsu.unionSets(u, v)) {
            res += dist;
        }
       } 
       return res;
    }
};
/*
    using prims
*/
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int N = points.size();
        unordered_map<int, vector<pair<int, int>>> adj;
        for(int i = 0; i < N; i++) {
            int x1 = points[i][0];
            int y1 = points[i][1];
            for(int j = i + 1; j < N; j++) {
                int x2 = points[j][0];
                int y2 = points[j][1];
                int dist = abs(x1 - x2) + abs(y1 - y2);
                adj[i].push_back({dist, j});
                adj[j].push_back({dist, i});
            }
        }
        int res = 0;
        unordered_set<int> visit;
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                                        greater<pair<int,int>>> minH;
        minH.push({0, 0});
        while(visit.size() < N) {
            auto curr = minH.top();
            minH.pop();
            int cost = curr.first;
            int i = curr.second;
            if(visit.count(i)) {
                continue;
            }
            res += cost;
            visit.insert(i);
            for(const auto& neighbor: adj[i]) {
                int neighbor_cost = neighbor.first;
                int neighbor_index = neighbor.second;
                if(!visit.count(neighbor_index)) {
                    minH.push({neighbor_cost, neighbor_index});
                }
            }
        }
        return res;
    }
};

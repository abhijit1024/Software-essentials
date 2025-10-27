/*
    https://leetcode.com/problems/cheapest-flights-within-k-stops/description/
    Time complexity - 
    Space complexity -

*/
/*
    Using dijsktra
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        const int INF = 1e9;
        vector<vector<pair<int, int>>> adj(n);
        for (auto& f : flights)
            adj[f[0]].push_back({f[1], f[2]});

        vector<vector<int>> dist(n, vector<int>(k + 2, INF));
        dist[src][0] = 0;

        using State = tuple<int, int, int>; // {cost, node, stops}
        priority_queue<State, vector<State>, greater<>> pq;
        pq.push({0, src, 0});

        while (!pq.empty()) {
            auto [cost, node, stops] = pq.top();
            pq.pop();

            if (node == dst) return cost;
            if (stops == k + 1) continue;

            for (auto& [next, price] : adj[node]) {
                int newCost = cost + price;
                if (newCost < dist[next][stops + 1]) {
                    dist[next][stops + 1] = newCost;
                    pq.push({newCost, next, stops + 1});
                }
            }
        }

        return -1;
    }
};

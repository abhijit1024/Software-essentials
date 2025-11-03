/*
    https://leetcode.com/problems/reconstruct-itinerary/
    TC- O(V + E) + O(ElogE) + O(E)
    SC - O(V + E) 
*/
class Solution {
public:
    void eulerPath(string curr, unordered_map<string, deque<string>>& g,
                    vector<string>& order) {
                        while(!g[curr].empty()) {
                            auto edge = g[curr].front();
                            g[curr].pop_front();
                            eulerPath(edge, g, order);
                        }
                        order.emplace_back(curr);
                    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, deque<string>> g;
        for(auto edge: tickets) {
            g[edge[0]].emplace_back(edge[1]);
        }
        for(auto [vertex, edges]: g) 
            sort(g[vertex].begin(), g[vertex].end());

        vector<string> order;
        eulerPath("JFK", g, order);


        reverse(order.begin(), order.end());
        return order;

    }
};
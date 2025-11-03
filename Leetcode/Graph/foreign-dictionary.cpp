/*  
    https://neetcode.io/problems/foreign-dictionary?list=neetcode150
    Tc - O(V + E)
    Sc - O(V + E)
*/
class Solution {
public:
    string topologicalSortBfs(unordered_map<char, unordered_set<char>>& g) {
        unordered_map<char, int> indegree;
        queue<char> q;
        string order; 
        //compute indegree
        for(auto u: g) {
            char src = u.first;
            for(auto neighbor: g[src]) {
                indegree[neighbor]++;
            }
        }
        //if no dependency add 
        for(auto u: g) {
            char src = u.first;
            if(!indegree[src]) 
                q.emplace(src);
        }
        //bfs traversal for indegree check
        while(!q.empty()) {
            auto curr = q.front();
            q.pop();
            order += curr;
            //reduce indegree of the neighbor
            for(auto neighbor: g[curr]) {
                --indegree[neighbor];
                if(!indegree[neighbor]) 
                    q.emplace(neighbor);
            }
        }
        return order.size() < g.size() ? "" : order;
    }
    string foreignDictionary(vector<string>& words) {
        unordered_map<char, unordered_set<char>> g;
        for(auto& word: words) {
            for(auto ch: word) {
                if(!g.count(ch))
                    g[ch] = unordered_set<char>();
            }
        }
        //iterate over adjacent word
        for(int w = 0; w + 1 < words.size(); w++) {
            int common_len = min(words[w].size(), words[w + 1].size());
            if(words[w + 1].size() <  words[w].size() &&
                  words[w].substr(0, common_len) == words[w + 1].substr(0, common_len)) {
                    return "";
            }
            //compare character one by one
            for(int i = 0; i < common_len; i++) {
                char src = words[w][i], dst = words[w + 1][i];
                if(src!= dst) {   
                    g[src].emplace(dst);
                    break;
                }
            }
        }
        string order = topologicalSortBfs(g);
        return order; 
    }
};

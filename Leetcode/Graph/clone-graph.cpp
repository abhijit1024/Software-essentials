/*
    https://leetcode.com/problems/clone-graph/description/
    Dfs sol
    Time complexity - O(V + E) ,where v is the number of vertices, and E is the no. of edges
    Space compleixty - O(V)
*/
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* dfs(Node* node, unordered_map<Node*, Node*>& clone) {
        if(node == nullptr) 
            return nullptr;
        if(clone.count(node)) 
            return clone[node];
        
        clone[node] = new Node(node->val);

        for(auto neighbor: node->neighbors) {
            clone[node]->neighbors.push_back(dfs(neighbor, clone));
        }
        return clone[node];
    }
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> clone;
        return dfs(node, clone);
    }
};

/*
    https://leetcode.com/problems/clone-graph/description/
    Dfs sol
    Time complexity - O(V + E) ,where v is the number of vertices, and E is the no. of edges
    Space compleixty - O(V) (stack space) for output space will be O(V + E) as cloned graph
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
/*
    TC - O(V + E) For each V we iterate E edges
    SC - O(V) for map and queue , O(V + E) for the cloned graph
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
    Node* bfs(Node* curr, unordered_map<Node*, Node*>& node_map) {
        if(!curr) return nullptr;
        Node* clone = new Node(curr->val);
        node_map.emplace(curr, clone);
        queue<Node*> q;
        q.emplace(curr);

        while(!q.empty()) {
            auto curr = q.front();
            q.pop();
            
            for(auto neighbor: curr->neighbors) {
                if(!node_map.count(neighbor)) {
                    Node* clonedNode = new Node(neighbor->val);
                    q.emplace(neighbor);
                    node_map[neighbor] = clonedNode;
                }
                node_map[curr]->neighbors.emplace_back(node_map[neighbor]);
            }
        }
        return node_map[curr];
    }
    Node* cloneGraph(Node* node) {
        if(!node) return nullptr;
        unordered_map<Node*, Node*> node_map;
        return bfs(node, node_map);
    }
};
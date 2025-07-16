/*
    https://leetcode.com/problems/binary-tree-postorder-traversal/
    Time complexity - O(n)
    Space complexity - O(n)
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    vector<int> res;
private:
    void postorder(TreeNode* node) {
        if(!node) {
            return;
        }
        postorder(node->left);
        postorder(node->right);
        res.push_back(node->val);
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        postorder(root);
        return res;
    }
};
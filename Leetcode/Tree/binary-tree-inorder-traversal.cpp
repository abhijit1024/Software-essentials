/*
    https://leetcode.com/problems/binary-tree-inorder-traversal/description/
    Time complexity - O(n);
    Space complexity - O(n);
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
    void inorder(TreeNode* node) {
        if(!node) {
            return;
        }
        inorder(node->left);
        res.push_back(node->val);
        inorder(node->right);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        inorder(root);
        return res;    
    }
};
/*
    Iterative soln
    Time complexity - O(n)
    Space complexity - O(n)
*/

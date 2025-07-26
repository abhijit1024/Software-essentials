/*
    https://leetcode.com/problems/binary-tree-maximum-path-sum/description/
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
private:
    int dfs(TreeNode* root, int& res) {
        if(!root) {
            return 0;
        }
        int left = max(dfs(root->left, res), 0);
        int right = max(dfs(root->right, res), 0);

        res = max(res, root->val + left + right);
        return root->val + max(left , right);
    }
public:
    int maxPathSum(TreeNode* root) {
        int res = root->val;
        dfs(root, res);
        return res;
    }
};
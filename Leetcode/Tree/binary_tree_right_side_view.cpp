/*
    https://leetcode.com/problems/binary-tree-right-side-view/description/
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
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            TreeNode* rightSide = nullptr;
            int len = q.size();

            for(int i = 0; i < len; i++) {
                TreeNode* node = q.front();
                q.pop();
                if(node) {
                    rightSide = node;
                    q.push(node->left);
                    q.push(node->right);
                }
            }
            if(rightSide) {
                res.push_back(rightSide->val);
            }
        }
        return res;
    }
};

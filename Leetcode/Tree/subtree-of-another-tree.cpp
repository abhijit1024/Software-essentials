/*
    https://leetcode.com/problems/subtree-of-another-tree/description/
    Time complexity - O(m+n) 
    Space complexity - O(m+n)
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
    bool sameTree(TreeNode* root, TreeNode* subRoot) {
        if(!root && ! subRoot) {
            return true;
        }
        if(root && subRoot && root-> val == subRoot-> val) {
            return sameTree(root->left, subRoot->left) &&
                    sameTree(root->right, subRoot->right);
        }
        return false;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!subRoot) {
            return true;
        }
        if(!root) {
            return false;
        }
        return sameTree(root, subRoot) ||
                isSubtree(root->left, subRoot) ||
                isSubtree(root->right, subRoot);
    }
};
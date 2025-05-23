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
    TreeNode* prev = NULL;

    bool isValidBST(TreeNode* root) {
        if (!root) return true;

        // check left subtree
        if (!isValidBST(root->left)) return false;

        // current node must be greater than the last visited node
        if (prev && root->val <= prev->val) return false;

        // update prev to current node
        prev = root;

        // check right subtree
        return isValidBST(root->right);
    }
};

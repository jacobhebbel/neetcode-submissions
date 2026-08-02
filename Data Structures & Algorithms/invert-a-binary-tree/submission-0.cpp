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
    
    void invert(TreeNode* node)
    {
        if (node->left != nullptr) invert(node->left);
        if (node->right != nullptr) invert(node->right); 

        TreeNode* temp = node->left;
        node->left = node->right;
        node->right = temp;
    }
    
    TreeNode* invertTree(TreeNode* root) {

        if (root != nullptr) invert(root);
        return root;
    }
};

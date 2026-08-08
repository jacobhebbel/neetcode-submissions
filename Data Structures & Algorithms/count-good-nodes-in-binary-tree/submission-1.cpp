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

    void explore(TreeNode* node, int mx_val, int &good_count)
    {
        if (!node) return;

        if (node->val >= mx_val)
        {
            good_count++;
            mx_val = node->val;
        }

        explore(node->left, mx_val, good_count);
        explore(node->right, mx_val, good_count);

        return;
    }
    
    int goodNodes(TreeNode* root) {
        int good_count = 0;
        if (root) explore(root, root->val, good_count);
        return good_count;
    }
};

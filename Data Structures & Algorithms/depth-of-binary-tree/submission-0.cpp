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

    void explore(TreeNode* node, int this_depth, int &max_depth)
    {
        // increment depth for exploring this node
        ++this_depth;
        max_depth = this_depth > max_depth ? this_depth : max_depth;
        if (node->left) explore(node->left, this_depth, max_depth);
        if (node->right) explore(node->right, this_depth, max_depth);
    }

    int maxDepth(TreeNode* root) {
        
        int max_depth = 0;
        int this_depth = 0;
        if (root != nullptr) explore(root, this_depth, max_depth);

        return max_depth;
    }
};

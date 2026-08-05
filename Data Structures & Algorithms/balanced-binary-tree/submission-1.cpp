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
    
    int explore(TreeNode* node, bool &tree_balanced)
    {
        if (!node) return 0;
        
        int l_ht = explore(node->left, tree_balanced);
        int r_ht = explore(node->right, tree_balanced);

        if (std::abs(l_ht - r_ht) > 1) tree_balanced = false;
        return 1 + std::max(l_ht, r_ht);
    }
    
    bool isBalanced(TreeNode* root) {

        int depth = 0;
        bool is_balanced = true;
        if (root) int foobar = explore(root, is_balanced);

        return is_balanced;
            
    }
};

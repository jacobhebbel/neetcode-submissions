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

    // Height-balanced: no left-right children heights can differ by more than 1

    // post-order traversal: get left height, right height, then compare
    
    int explore(TreeNode* node, bool &is_balanced)
    {
        // base cases
        if (!is_balanced) return -1;
        if (!node) return -1;

        // post-order traversal
        int height_left = explore(node->left, is_balanced);
        int height_right = explore(node->right, is_balanced);

        // compare heights
        bool subtree_balanced = std::abs(
            height_left - height_right
        ) < 2;

        is_balanced = is_balanced ? subtree_balanced : false;

        int this_height = std::max(height_left, height_right) + 1;
        return this_height;
    }

    bool isBalanced(TreeNode* root) {
        bool tree_balanced = true;
        if (root) {
            int tree_height = explore(
                root, 
                tree_balanced
            );
        }

        return tree_balanced;
    }
};

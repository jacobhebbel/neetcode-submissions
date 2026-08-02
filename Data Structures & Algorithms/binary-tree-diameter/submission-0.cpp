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

    int explore(TreeNode* node, int &max_diameter)
    {
        int left_len = 0, right_len = 0;
        if (node->left) 
            left_len = explore(node->left, max_diameter);
        if (node->right) 
            right_len = explore(node->right, max_diameter);

        int this_diameter = left_len + right_len;
        max_diameter = std::max(max_diameter, this_diameter);

        return std::max(left_len, right_len) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        
        int max_diameter = 0;
        int longest_path = 0;
        if (root) 
            longest_path = explore(root, max_diameter) - 1;
        
        return std::max(longest_path, max_diameter);
    }
};
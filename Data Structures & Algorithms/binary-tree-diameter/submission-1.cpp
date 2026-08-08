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

    /*
        Strategy: solve the subproblem for each subtree
        1. explore postorder, returning node heights
        2. at some node: 
            - get the left and right child heights.
            - compare max height with left height + right height
            - return 

        a tree of one node has height 0
    */

    int explore(TreeNode* node, int &mx_diam)
    {
        if (!node) return 0;

        int left_height = explore(node->left, mx_diam);
        int right_height = explore(node->right, mx_diam);

        int this_diam = left_height + right_height;
        mx_diam = std::max(mx_diam, this_diam);

        return 1 + std::max(left_height, right_height);   
    }

    int diameterOfBinaryTree(TreeNode* root) {
        
        int maximum_diameter = 0;
        int height_of_tree = 0;
        if (root)
        {
            height_of_tree = explore(
                root, maximum_diameter
            ) - 1;
        }

        return std::max(maximum_diameter, height_of_tree);
    }
};
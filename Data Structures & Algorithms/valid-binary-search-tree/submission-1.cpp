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

    // at each tree, ask: 
    // -> is left smaller than me?
    // -> is right bigger than me?

    void explore(TreeNode* node, bool &is_bst, int lb, int rb)
    {
        // base cases
        if (!is_bst) return;
        if (!node) return;

        int v = node->val;

        bool subtree_bst = (
            lb < v and v < rb
        );

        is_bst = is_bst? subtree_bst : false;
        
        explore(node->left, is_bst, lb, node->val);
        explore(node->right, is_bst, node->val, rb);
        return;
    }

    bool isValidBST(TreeNode* root) {
        
        bool answer = true;
        explore(root, answer, INT_MIN, INT_MAX);
        return answer;
    }
};

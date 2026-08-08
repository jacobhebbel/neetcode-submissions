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

    TreeNode* explore(TreeNode* node, int &mn, int &mx)
    {
        // use the min and max to pick which node to traverse
        // if mn <= n->val <= mx then n is the answer
        // we want the biggest n satisfying this condition
        // so we return early!

        int v = node->val;
        bool lca = mn <= v and mx >= v;
        if (lca) return node;

        if (v < mn)
        {
            return explore(node->right, mn, mx);
        }

        else
        {
            return explore(node->left, mn, mx);
        }
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        // we use these to pick which subtree to explore
        int small_target = std::min(p->val, q->val);
        int large_target = std::max(p->val, q->val);
 
        return explore(
            root, 
            small_target,
            large_target
        );
    }
};

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

    void explore(TreeNode* p, TreeNode* q, bool &similar)
    {
        // if both are nullptr then they're the same
        // if only one is nullptr then they are different
        // if both are valid with different data they're different
        // if both are valid with same data then they're similar

        // check state
        bool p_null = p == nullptr, q_null = q == nullptr;
        if (p_null != q_null)
        {
            similar = false;
            std::cout << "one is nullptr" << std::endl;
            return;
        } else if (!p) return;

        // check structure
        if (p->val != q->val)
        {
            similar = false;
            std::cout << "one is different" << std::endl;
        }

        // explore
        explore(p->left, q->left, similar);
        explore(p->right, q->right, similar);


    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        
        bool same = true;
        explore(p, q, same);

        return same;
    }
};

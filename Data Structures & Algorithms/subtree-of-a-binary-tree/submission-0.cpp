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
        Strategy: 
        1. explore the tree, in in-order traversal
        2. at each node, check if we equal the subRoot
            If we do: any traversal to see if we 
    */

    void explore(TreeNode* a, TreeNode* b, bool &is_equal)
    {   
        // speeds up exit
        if (is_equal == false) return;

        // if both are undefined: ok. else: not equal
        if (a == nullptr or b == nullptr)
        {
            if (a == nullptr and b == nullptr)
            {
                return;
            }

            else {
                is_equal = false;
                return;
            }
        }

        is_equal = is_equal ? (a->val == b->val) : false;
        explore(a->left, b->left, is_equal);
        explore(a->right, b->right, is_equal);
        return;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        
        std::queue<TreeNode*> q;
        TreeNode* node = nullptr;
        q.push(root);

        while (q.empty() == false)
        {
            node = q.front();
            q.pop();
            if (node == nullptr) continue;

            if (node->val == subRoot->val)
            {
                // run dfs to explore this tree
                bool is_equal = true;
                explore(node, subRoot, is_equal);
                if (is_equal) return true;
            }

            // add this node's children to the queue
            q.push(node->left); q.push(node->right);
        }

        return false;
    }
};

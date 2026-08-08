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

    void explore(TreeNode* node, std::queue<int> &q)
    {
        if (node == nullptr) return;

        explore(node->left, q);
        q.push(node->val);
        explore(node->right, q);
        
        return;
    }

    int kthSmallest(TreeNode* root, int k) {

        std::queue<int> sorted_nodes{};
        explore(root, sorted_nodes);

        int ans = -1;
        while (k--)
        {
            ans = sorted_nodes.front();
            sorted_nodes.pop();
        }

        return ans;
    }
};

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

    vector<vector<int>> levelOrder(TreeNode* root) {
        
        std::vector<vector<int>> ans;
        std::queue<TreeNode*> q;
        
        // guards against nullptr input
        if (root) q.push(root);

        TreeNode* node = nullptr;
        int level = 0;
        while (!q.empty())
        {   
            ans.push_back({});
            int num_nodes_on_level = q.size();
            while (num_nodes_on_level--)
            {   
                // get this node
                node = q.front();
                q.pop();

                // save it
                ans[level].push_back(node->val);

                // push its children if they exist
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            level += 1;
        }

        return ans;
    }
};

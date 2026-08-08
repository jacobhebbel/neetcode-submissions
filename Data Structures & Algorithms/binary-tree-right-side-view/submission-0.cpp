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

    vector<int> rightSideView(TreeNode* root) {
        std::vector<int> answer{};

        std::queue<TreeNode*> q;
        if (root) q.push(root);
        
        TreeNode* node = nullptr;
        while (!q.empty())
        {   
            // we want the last element in each level
            int nodes_in_level = q.size();
            while (nodes_in_level--)
            {
                // fast-adds their children and skips them
                node = q.front();
                q.pop();
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            // node points to the last node in the level
            answer.push_back(node->val);
        }
        
        
        return answer;        
    }
};

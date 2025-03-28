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
        void process(TreeNode* root, vector<int>& res) {
            if (!root) return ;
            process(root->left, res);
            res.emplace_back(root->val);
            process(root->right, res);
        }
        vector<int> inorderTraversal(TreeNode* root) {
            vector<int> res;
            process(root, res);
            return res;
        }
    };
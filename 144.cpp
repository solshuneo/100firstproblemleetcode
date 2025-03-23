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
        void gen(TreeNode* root, vector<int>& ans) {
            if (!root) return ;
            ans.emplace_back(root->val);   
            gen(root->left, ans);
            gen(root->right, ans);
        }
        vector<int> preorderTraversal(TreeNode* root) {
            vector<int> ans;
            gen(root, ans);
            return ans;
        }
    };
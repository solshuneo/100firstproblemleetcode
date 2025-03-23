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
        void gen(TreeNode* root, vector<string>& ans, string cur) {
            if (!root) {
                ans.emplace_back(cur);
                return ;
            }
            cur += "->" + to_string(root->val);
            if (!root->right) {
                gen(root->left, ans, cur);
                return;
            }
            if (!root->left) {
                gen(root->right, ans, cur);
                return;
            }
            gen(root->right, ans, cur);
            gen(root->left, ans, cur);
        }
        vector<string> binaryTreePaths(TreeNode* root) {
            vector<string> ans;
            if (!root) return ans;
            if (!root->left)
                gen(root->right, ans, to_string(root->val));
            else if (!root->right) gen(root->left, ans, to_string(root->val));
            else {
                gen(root->right, ans, to_string(root->val));
                gen(root->left, ans, to_string(root->val));
            }
            return ans;
        }
    };
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
        void getValue(TreeNode* root, vector<int>& val) {
            if (root == nullptr) return ;
            val.emplace_back(root->val);
            getValue(root->left, val);
            getValue(root->right, val);
        }
        void recoverTree(TreeNode* root) {
            vector<int> val;
            getValue(root, val);
            sort(val.begin(), val.end());
            cout << val.size() << endl;
            cover(root, val);
        }
        void cover(TreeNode* root, vector<int>& val) {
            if (!root) return ;
            cover(root->right, val);
            root->val = *val.rbegin();
            val.pop_back();
            cover(root->left, val);
        }
    };
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
        bool both(TreeNode* a, TreeNode* b) {
            bool ca = a == nullptr;
            bool cb = b == nullptr;
            if (ca ^ cb) return false;
            if (ca) return true;
            cout << a->val << ' ' << b->val << endl;
            if (a->val == b->val) {
                return both(a->left, b->right) && both(a->right, b->left);
            }
            return false;
        }
        bool isSymmetric(TreeNode* root) {
            return both(root->left, root->right);    
        }
    };
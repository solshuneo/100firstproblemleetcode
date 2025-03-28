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
        bool isValidBST(TreeNode* root, long long lhs = -(1LL<<31) - 1, long long rhs = 1LL<< 31) {
            if (!root) return false;
            if (root->left) {
                if (root->val <= root->left->val) return false;
                if (!isValidBST(root->left, lhs, root->val - 1)) return false;
            }
            if (root->right) {
                if (root->val >= root->right->val) return false;
                if (!isValidBST(root->right, root->val + 1, rhs)) return false;
            }
            if (root->val < lhs) return false;
            if (root->val > rhs) return false;
            return true;
        }
    };
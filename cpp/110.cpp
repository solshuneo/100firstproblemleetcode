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
        bool checker(TreeNode* root, int& depth) {
            if (!root) return true;
            int depthLeft = depth, depthRight = depth;
            if (checker(root->left, depthLeft) && checker(root->right, depthRight)) {
                cout << depthLeft << ' ' << depthRight << ' ' << root->val << endl;
                depth = max(depthLeft, depthRight) + 1;
                return abs(depthLeft - depthRight) <= 1;
            }
            return false;
        }
        bool isBalanced(TreeNode* root) {
            int depth = 0;
            return checker(root, depth);
        }
    };
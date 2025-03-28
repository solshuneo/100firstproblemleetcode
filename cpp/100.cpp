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
        bool isSameTree(TreeNode* p, TreeNode* q) {
            if (!p && !q) return true;
            if (!p || !q) return false;
            if (isLeaf(p) && isLeaf(q)) {
                return p->val == q->val;
            }
            return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    
        }
    private:
        bool isLeaf(TreeNode* a) {
            return (!a->left & !a->right);
        }
    };
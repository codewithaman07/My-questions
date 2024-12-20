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
    void solve(TreeNode* leftch, TreeNode* rightch, int level){
        if(leftch == NULL || rightch == NULL) return;
        if(level & 1){
            auto temp = leftch->val;
            leftch->val = rightch->val;
            rightch->val = temp;
        }
        solve(leftch->left, rightch->right, level+1);
        solve(leftch->right, rightch->left, level+1);
    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        solve(root->left, root->right, 1);
        return root;
    }
};
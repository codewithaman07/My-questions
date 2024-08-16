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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return 0;
        targetSum-=root->val;
        if(root->left == nullptr && root->right == nullptr){
            if(targetSum) return 0;
            else return 1;
        }
        return (root->left && hasPathSum(root->left,targetSum) || root->right && hasPathSum(root->right, targetSum));
    }
};
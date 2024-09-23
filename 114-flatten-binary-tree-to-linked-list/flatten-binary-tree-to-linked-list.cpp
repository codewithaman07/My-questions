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
    void pre(TreeNode* root){
        if(!root) return;
        pre(root->left);
        pre(root->right);
        TreeNode* rightnode = root->right;
        root->right = root->left;
        root->left = nullptr;
        TreeNode* curr = root;
        while(curr->right) curr = curr->right;
        curr->right = rightnode;


    }
    void flatten(TreeNode* root) {
        pre(root);
    }
};
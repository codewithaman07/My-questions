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
    void solve(vector<int>&inorder, TreeNode* root){
        if(root == nullptr) return;
        solve(inorder, root->left);
        inorder.push_back(root->val);
        solve(inorder, root->right); 
    }
    void fun(int &i, vector<int>&inorder, TreeNode* root){
        if(root == nullptr) return;
        fun(i, inorder, root->left);
        root->val = inorder[i++];
        fun(i, inorder, root->right);
    }
    void recoverTree(TreeNode* root) {
        if(root == nullptr) return;
        vector<int>inorder;
        solve(inorder, root);
        sort(inorder.begin(), inorder.end());
        int i = 0;
        fun(i, inorder, root);

    }
};
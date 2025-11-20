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
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int &idx, int s, int e){
        if(s>e) return nullptr;
        TreeNode* root = new TreeNode(preorder[idx]);
        int i = s;
        while(i<=e){
            if(inorder[i] == root->val) break;
            i++;
        }
        idx++;
        root->left = solve(preorder, inorder, idx, s, i-1);
        root->right = solve(preorder, inorder, idx, i+1, e);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size(), idx = 0;
        return solve(preorder, inorder, idx, 0, n-1);
    }
};
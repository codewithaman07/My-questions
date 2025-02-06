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
    TreeNode* solve(vector<int>&in,vector<int>&post, int i,int j, int &idx,unordered_map<int,int>&mp){
        if(i>j) return nullptr;
        int temp = post[idx--];
        int x = mp[temp];
        TreeNode* root = new TreeNode(temp);
        root->right = solve(in, post, x+1, j, idx, mp);
        root->left = solve(in, post, i, x-1, idx, mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& in, vector<int>& post) {
        unordered_map<int,int>mp;
        int n = in.size();
        for(int i = 0; i<n; i++) mp[in[i]] = i;
        int idx = post.size()-1;
        return solve(in, post, 0, n-1, idx, mp);
    }
};
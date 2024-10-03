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
    bool solve(TreeNode* root, unordered_set<int>&st, int k){
        if(!root) return 0;
        if(st.find(k - root->val) != st.end()){
            return 1;
        }
        st.insert(root->val);
        bool left = solve(root->left, st, k);
        bool right = solve(root->right, st, k);
        return left || right;
    }
    bool findTarget(TreeNode* root, int k) {
        if(!root) return 0;
        unordered_set<int>st;
        return solve(root, st, k);
    }
};
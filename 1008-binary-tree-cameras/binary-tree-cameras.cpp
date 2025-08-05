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
    void solve(unordered_set<TreeNode*>&st, TreeNode* root, int &ans, TreeNode* parent){
        if(!root) return;
        solve(st, root->left, ans, root);
        solve(st, root->right, ans, root);
        if((parent == nullptr && !st.count(root)) || !st.count(root->left) || !st.count(root->right)){
            ans++;
            st.insert(parent);
            st.insert(root);
            st.insert(root->left);
            st.insert(root->right);
        }
    }
    int minCameraCover(TreeNode* root) {
        int ans  = 0;
        unordered_set<TreeNode*>st;
        st.insert(nullptr);
        solve(st, root, ans, nullptr);
        return ans;
    }
};
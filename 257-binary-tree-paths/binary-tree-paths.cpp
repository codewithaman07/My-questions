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
    void solve(TreeNode* root, vector<string>&ans, string s){
        if(!root) return;
        string a = to_string(root->val);
        if(!(root->left) && !(root->right)){
            s+=a;
            ans.push_back(s);
            return;
        }
        solve(root->left, ans, s+a+"->");
        solve(root->right, ans, s+a+"->");
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        string s;
        vector<string>ans;
        solve(root,ans,s);
        return ans;
    }
};
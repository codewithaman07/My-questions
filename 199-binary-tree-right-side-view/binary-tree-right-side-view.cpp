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
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        if(root == nullptr) return ans;
        queue<TreeNode*>q;
        q.push(root);
        vector<vector<int>>vec;
        while(!q.empty()){
            int k = q.size();
            vector<int>level;
            while(k--){
                TreeNode* a = q.front();
                q.pop();
                level.push_back(a->val);
                if(a->left) q.push(a->left);
                if(a->right) q.push(a->right);
            }
            vec.push_back(level);
        }
        for(auto i : vec){
            ans.push_back(i.back());
        }
        return ans;
    }
};

 
/*class Solution {
public:
    void solve(TreeNode* root, vector<int>&ans, int level){
        if(!root) return;
        if(ans.size() == level){
            ans.push_back(root->val);
        }
        solve(root->right,ans,level+1);
        solve(root->left, ans, level+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        int level = 0;
        if(!root) return ans;
        solve(root,ans,level);
        return ans;
    }
};
*/

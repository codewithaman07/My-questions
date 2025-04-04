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
    vector<TreeNode*>level(TreeNode* root){
        vector<TreeNode*>x;
        if(!root) return x;
        queue<TreeNode*>q;
        vector<vector<TreeNode*>>ans;
        q.push(root);
        while(!q.empty()){
            int cnt = q.size();
            vector<TreeNode*>temp;
            while(cnt--){
                auto node = q.front(); q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                temp.push_back(node);
            }
            ans.push_back(temp);
        }
        int n = ans.size();
        return ans[n-1];
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || root == p || root == q) return root;
        TreeNode* l = lowestCommonAncestor(root->left, p, q);
        TreeNode* r = lowestCommonAncestor(root->right, p, q);
        if(!l) return r;
        else if(!r) return l;
        else return root;
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        vector<TreeNode*>arr = level(root);
        auto p = arr[0], q = arr[arr.size()-1];
        return lowestCommonAncestor(root, p,q);
    }
};
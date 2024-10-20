/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void child_parent(TreeNode* root, unordered_map<TreeNode*, TreeNode*>&parent){
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node->left){
                q.push(node->left);
                parent[node->left] = node;
            }
            if(node->right){
                q.push(node->right);
                parent[node->right] = node;
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*>parent;
        child_parent(root, parent);
        queue<TreeNode*>q;
        q.push(target);
        unordered_map<TreeNode*, bool>seen;
        seen[target] = 1;
        int curr = 0;
        while(!q.empty()){
            if(curr == k) break;
            curr++;
            int n = q.size();
            for(int i = 0; i<n; i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left && !seen[node->left]){
                    seen[node->left] = 1;
                    q.push(node->left);
                }
                if(node->right && !seen[node->right]){
                    seen[node->right] = 1;
                    q.push(node->right);
                }
                if(parent[node] && !seen[parent[node]]){
                    seen[parent[node]] = 1;
                    q.push(parent[node]);
                }
            }
        }
        vector<int>ans;
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};
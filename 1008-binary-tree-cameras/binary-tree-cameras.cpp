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
    void calculateCameras(TreeNode* root, int &numCameras, unordered_set<TreeNode*>&nodes, TreeNode* parent){
        if(!root) return;
        calculateCameras(root->left, numCameras, nodes, root);
        calculateCameras(root->right, numCameras, nodes, root);
        if((parent == nullptr && !nodes.count(root)) || (!nodes.count(root->left) || (!nodes.count(root->right)))){
            numCameras++;
            nodes.insert(root);
            nodes.insert(root->left);
            nodes.insert(root->right);
            nodes.insert(parent);
        }
    }
    int minCameraCover(TreeNode* root) {
        int numCameras = 0;
        unordered_set<TreeNode*>nodes;
        nodes.insert(nullptr);
        calculateCameras(root, numCameras, nodes, nullptr);
        return numCameras;
    }
};



















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
    void inorder(TreeNode* root, vector<int>&arr){
        if(!root) return;
        inorder(root->left, arr);
        arr.push_back(root->val);
        inorder(root->right, arr);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int>arr;
        inorder(root, arr);
        int l = 0, r = arr.size()-1;
        while(l<r){
            if(arr[l]+arr[r] == k) return 1;
            else if(arr[l]+arr[r] < k) l++;
            else r--;
        }
        return 0;
    }
};

// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
// class Solution {
// public:
//     bool solve(TreeNode* root, unordered_set<int>&st, int k){
//         if(!root) return 0;
//         if(st.find(k - root->val) != st.end()){
//             return 1;
//         }
//         st.insert(root->val);
//         bool left = solve(root->left, st, k);
//         bool right = solve(root->right, st, k);
//         return left || right;
//     }
//     bool findTarget(TreeNode* root, int k) {
//         if(!root) return 0;
//         unordered_set<int>st;
//         return solve(root, st, k);
//     }
// };
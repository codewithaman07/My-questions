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
    void solve(TreeNode* root, vector<vector<long long>>& ans, int level) {
        if (!root) return;
        if (ans.size() <= level) ans.push_back({});
        ans[level].push_back(root->val);
        solve(root->left, ans, level + 1);
        solve(root->right, ans, level + 1);
    }

    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<vector<long long>> ans;
        solve(root, ans, 0);
        vector<long long> arr;
        for(auto i : ans){
            long long sum = accumulate(i.begin(), i.end(), 0ll);
            arr.push_back(sum);
        }
        sort(arr.begin(), arr.end(), greater<long long>());
        if(k > arr.size()) return -1;
        return arr[k-1];
    }
};

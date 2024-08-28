class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        vector<int>nums;
        int n = mat.size(), m = mat[0].size();
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                nums.push_back(mat[i][j]);
            }
        }
        sort(nums.begin(), nums.end());
        return nums[k-1];
    }
};
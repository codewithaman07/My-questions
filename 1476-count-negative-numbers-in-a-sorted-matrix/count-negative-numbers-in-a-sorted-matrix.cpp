class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), ans = 0;
        for(int i = 0; i<n; i++){
            int idx = upper_bound(grid[i].begin(), grid[i].end(), 0, greater<int>())-grid[i].begin();
            ans+=(m-idx);
        }
        return ans;
    }
};
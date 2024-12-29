class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), ans = 0;
        for(int j = 0; j<m; j++){
            int prev = grid[0][j];
            for(int i = 1; i<n; i++){
                if(grid[i][j]<=prev){
                    prev++;
                    ans+=(prev-grid[i][j]);
                }
                else prev = grid[i][j];
            }
        }
        return ans;
    }
};
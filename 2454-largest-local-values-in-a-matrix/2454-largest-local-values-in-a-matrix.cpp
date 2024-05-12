class Solution {
public:
    int maxx(vector<vector<int>> &grid, int p, int q){
        int maxi = INT_MIN;
        for(int i = p; i<p+3; i++){
            for(int j = q; j<q+3; j++){
                maxi = max(maxi, grid[i][j]);
            }
        }
        return maxi;
    }
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = n-2;
        // vector<vector<int>>ans(m, vector<int>(m,0));
        for(int i = 0; i<m; i++){
            for(int j = 0; j<m; j++){
                grid[i][j] = maxx(grid, i , j);
            }
        }
        grid.resize(m);
        for(int i =0; i<m; i++){
            grid[i].resize(m);
        }
        return grid;
    }
};
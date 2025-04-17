class Solution {
public:
    int dr[4] = {0,0,-1,1};
    int dc[4] = {-1,1,0,0};
    void solve(int i, int j, vector<vector<int>>&vis, vector<vector<char>>&grid){
        int n = grid.size(), m = grid[0].size();
        if(i>=n || i<0 || j<0 || j>=m || grid[i][j] == '0' || vis[i][j]) return;
        vis[i][j] = 1;
        for(int k = 0; k<4; k++){
            solve(i+dr[k], j+dc[k], vis,grid);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size(), cnt = 0;
        vector<vector<int>>vis(n, vector<int>(m, 0));
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(vis[i][j] || grid[i][j] == '0') continue;
                solve(i,j,vis, grid);
                cnt++;
            }
        }
        return cnt;
    }
};
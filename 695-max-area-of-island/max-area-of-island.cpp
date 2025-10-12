class Solution {
public:
    int dr[4] = {1,-1,0,0};
    int dc[4] = {0,0,-1,1};
    bool valid(int i, int j, vector<vector<int>>&grid, vector<vector<bool>>&vis){
        int n = grid.size(), m = grid[0].size();
        if(i<0 || i>=n || j<0 || j>=m || vis[i][j] == 1 || grid[i][j] == 0) return 0;
        return 1;
    }
    int solve(int i, int j, vector<vector<int>>&grid, vector<vector<bool>>&vis){
        int cnt = 1;
        vis[i][j] = 1;
        for(int k = 0; k<4; k++){
            int dx = i+dr[k];
            int dy = j+dc[k];
            if(!valid(dx,dy,grid,vis)) continue;
            cnt+=solve(dx,dy,grid,vis);
        }
        return cnt;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), maxi = 0;
        vector<vector<bool>>vis(n, vector<bool>(m,0));
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(!grid[i][j] || vis[i][j]) continue;
                maxi = max(maxi, solve(i,j,grid,vis));
            }
        }
        return maxi;
    }
};
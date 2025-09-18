class Solution {
public:
    int dr[4] = {-1,1,0,0};
    int dc[4] = {0,0,-1,1};
    bool isValid(int i, int j, int n, int m){
        if(i>=0 && i<n && j>=0 && j<m) return true;
        return false;
    }
    int dfs(int i, int j, int n, int m, vector<vector<int>>&mat, vector<vector<int>>&dp){
        if(dp[i][j] != -1) return dp[i][j];
        int ans = 1;
        for(int k = 0; k<4; k++){
            int nr = i+dr[k];
            int nc = j+dc[k];
            if(isValid(nr,nc,n,m) && mat[i][j] < mat[nr][nc]){
                ans = max(ans, 1+dfs(nr,nc,n,m,mat,dp));
            }
        }
        return dp[i][j] = ans;
    }
    int longestIncreasingPath(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size(), ans = 0;
        vector<vector<int>>dp(n, vector<int>(m,-1));
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                ans = max(ans, dfs(i,j,n,m,mat,dp));
            }
        }
        return ans;
    }
};
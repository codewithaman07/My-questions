class Solution {
public:
    int solve(int i, int j, string &s, vector<vector<int>>&dp){
        if(i == j) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        int mini = INT_MAX;
        for(int k = i; k<j; k++){
            mini = min(mini,solve(i,k,s,dp)+solve(k+1,j,s,dp));
        }
        if(s[i] == s[j]) mini--;
        return dp[i][j] = mini;
    }
    int strangePrinter(string s) {
        int n = s.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return solve(0,n-1,s,dp);
    }
};
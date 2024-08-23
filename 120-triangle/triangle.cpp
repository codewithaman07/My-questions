class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>>dp(n, vector<int>(n,0));
        for(int j = n-1; j>=0; j--) dp[n-1][j] = triangle[n-1][j];
        for(int i = n-2; i>=0; i--){
            for(int j = i; j>=0; j--){
                dp[i][j] = min(dp[i+1][j], dp[i+1][j+1])+triangle[i][j];
            }
        }
        return dp[0][0];
    }
};
auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();
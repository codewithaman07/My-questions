class Solution {
public:
    int minCost(int m, vector<int>& cuts) {
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(m);
        sort(cuts.begin(),cuts.end());
        int n = cuts.size();
        vector<vector<int>>dp(n, vector<int>(n,0));
        for(int l = n-2; l>=1; l--){
            for(int r = l; r<=n-2; r++){
                if(l>r) continue;
                int mini = INT_MAX;
                for(int i = l; i<=r; i++){
                    int ans = dp[l][i-1]+dp[i+1][r]+(cuts[r+1]-cuts[l-1]);
                    mini = min(ans,mini);
                }
                dp[l][r] = mini;
            }
        }
        return dp[1][n-2];
    }
};
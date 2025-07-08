class Solution {
public:
    int solve(vector<vector<int>>&events, vector<vector<int>>&dp, int i, int s, int k){
        int n = events.size();
        if(i>=n || k<=0) return 0;
        if(dp[i][k] != -1) return dp[i][k];
        int maxi = solve(events, dp, i+1, s, k);
        int idx = upper_bound(events.begin()+i+1, events.end(), events[i][1],[](int num, vector<int>&e){
            return num<e[0];
        }) - events.begin();
        maxi = max(maxi,solve(events, dp, idx, events[i][1], k-1)+events[i][2]);
        return dp[i][k] = maxi;
    }
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(),events.end());
        int n = events.size();
        vector<vector<int>>dp(n+1, vector<int>(k+1,-1));
        return solve(events, dp, 0, -1, k);
    }
};
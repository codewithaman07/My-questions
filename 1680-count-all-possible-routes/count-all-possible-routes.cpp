class Solution {
public:
    #define ll long long
    const int mod = 1e9+7;
    int solve(int n, int i, int e, int f, vector<int>&arr, vector<vector<int>>&dp){
        if(f<0) return 0;
        if(dp[i][f] != -1) return dp[i][f];
        ll ans = i == e ? 1 : 0;
        for(int j = 0;j<n; j++){
            if(i != j && abs(arr[i]-arr[j]) <= f){
                ans = (ans+(solve(n,j,e,f-abs(arr[i]-arr[j]), arr,dp)%mod))%mod;
            }
        }
        return dp[i][f] = ans;
    }
    int countRoutes(vector<int>& arr, int s, int e, int f) {
        int n = arr.size();
        vector<vector<int>>dp(n+1, vector<int>(f+1,-1));
        return solve(n,s,e,f,arr,dp);
    }
};
class Solution {
public:
    #define ll long long
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        vector<ll>low(n+1, 0), up(n+1,0);
        for(int i = 0; i<n; i++){
            low[i+1] = low[i]+grid[1][i];
            up[i+1] = up[i]+grid[0][i];
        }
        ll ans = LLONG_MAX;
        for(int i = 1; i<=n; i++){
            ans = min(ans, max(low[i-1], up[n]-up[i]));
        }
        return ans;
    }
};
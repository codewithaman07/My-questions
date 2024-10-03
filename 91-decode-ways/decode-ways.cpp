class Solution {
public:
    int dp[101];
    int solve(int idx, int &n, string &s){
        if(idx >= n) return 1;
        if(s[idx] == '0') return 0;
        if(dp[idx] != -1) return dp[idx];
        int one = solve(idx+1, n, s);
        int two = 0;
        if(idx+1 < n && (s[idx] == '1' || (s[idx] == '2' && s[idx+1]<='6'))){
            two = solve(idx+2, n, s);
        }
        return dp[idx] = one+two;
    }
    int numDecodings(string s) {
        int n = s.size();
        memset(dp, -1, sizeof(dp));
        return solve(0, n, s);
    }
};
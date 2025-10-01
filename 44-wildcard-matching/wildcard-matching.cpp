class Solution {
public:
    int dp[2001][2001];
    bool check(string &p, int j){
        for(int i = 0; i<=j; i++){
            if(p[i] != '*') return 0;
        }
        return 1;
    }
    bool solve(string &s, string &p, int i, int j){
        if(i<0 && j<0) return 1;
        if(i<0 && j>=0) return check(p,j);
        if(i>=0 && j<0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] == p[j] || p[j] == '?') return dp[i][j] = solve(s,p,i-1,j-1);
        else if(p[j] == '*') return dp[i][j] = solve(s,p,i-1,j) || solve(s,p,i,j-1) || solve(s,p,i-1,j-1); 
        else return dp[i][j] = 0;
    }
    bool isMatch(string s, string p) {
       int n = s.size(), m = p.size();
       memset(dp,-1, sizeof(dp));
       return solve(s,p, n-1, m-1);
    }
};
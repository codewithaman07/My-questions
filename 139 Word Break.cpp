class Solution {
public:
    bool solve(int idx, string &s, unordered_set<string>& st, vector<int>& memo) {
        int n = s.length();
        if (idx == n) return true;
        if (memo[idx] != -1) return memo[idx];
        
        for (int i = 1; i <= n - idx; i++) {
            string temp = s.substr(idx, i);
            if (st.find(temp) != st.end() && solve(idx + i, s, st, memo)) {
                return memo[idx] = true;
            }
        }
        return memo[idx] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        vector<int> memo(n, -1);
        return solve(0, s, st, memo);
    }
};

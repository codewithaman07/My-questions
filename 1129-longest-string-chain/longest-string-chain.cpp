class Solution {
public:
    static bool cmp1(string &s1, string &s2){
        return s1.size() < s2.size();
    }
    static bool cmp2(string &s1, string &s2){
        int n = s1.size();
        int m = s2.size();
        if(n != m+1) return 0;
        int i = 0, j = 0;
        while(i<n){
            if(j<m && s1[i] == s2[j]) i++, j++;
            else i++;
        }
        if(i == n && j == m) return 1;
        return 0;
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), cmp1);
        int n = words.size();
        vector<int>dp(n,1);
        int maxi = 0;
        for(int i = 0; i<n; i++){
            for(int prev = 0; prev<i; prev++){
                if(cmp2(words[i] , words[prev]) && dp[i] < 1+dp[prev]){
                    dp[i] = 1+dp[prev];
                }
            }
        }
        for(int i = 0; i<n; i++){
            maxi = max(maxi, dp[i]);
        }
        return maxi;
    }
};
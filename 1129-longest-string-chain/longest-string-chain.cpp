class Solution {
public:
    static bool cmp1(string &s1, string &s2){
        return s1.size() < s2.size();
    }
    static bool cmp2(string &s1, string &s2){
        if(s1.size() != s2.size()+1) return 0;
        int i = 0, j = 0;
        while(i<s1.size()){
            if(j<s2.size() && s1[i] == s2[j]) i++, j++;
            else i++;
        }
        if(i == s1.size() && j == s2.size()) return 1;
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
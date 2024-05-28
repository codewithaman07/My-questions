class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int l = 0, r = 0, ans = INT_MIN, cost = 0;
        int n = s.length();
        for( ; r<n; r++){
            cost+= abs(s[r]-t[r]);
            for( ; cost>maxCost; l++){
                cost-= abs(s[l] - t[l]);
            }
            ans = max(ans,r-l+1);
        }
        return ans;
    }
};

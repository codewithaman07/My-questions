class Solution {
public:
    int maxScore(string s) {
        int n = s.size(), maxi = 0, l = 0, r = 0;
        for(int i = 0; i<n; i++) r+=(s[i]-'0');
        for(int i = 0; i<n-1; i++){
            if(s[i] == '0') l++;
            else r--;
            maxi = max(maxi, l+r);
        }
        maxi = max(maxi, l+r);
        return maxi;
    }
};
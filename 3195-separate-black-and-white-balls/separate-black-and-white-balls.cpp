class Solution {
public:
    #define ll long long
    long long minimumSteps(string s) {
        ll n = s.size(), cnt = 0, ans = 0;
        for(ll i = 0; i<n; i++){
            if(s[i] == '1') cnt++;
            if(s[i] == '0') ans+=cnt;
        }
        return ans;
    }
};
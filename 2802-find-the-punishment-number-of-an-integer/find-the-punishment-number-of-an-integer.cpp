class Solution {
public:
    #define ll long long
    bool fun(string &s, int target, int i, int sum){
        int n = s.size();
        if(i == n) return sum == target;
        int num = 0;
        for(int j = i; j<n; j++){
            num = (num*10 + s[j]-'0');
            if(fun(s, target, j+1, sum+num)) return 1;
        }
        return 0;
    }
    ll solve(ll i){
        ll sq = i*i;
        string s = to_string(sq);
        if(fun(s,i,0,0)) return sq;
        return 0;
    }
    int punishmentNumber(int n) {
        ll ans = 0;
        for(int i = 1; i<=n; i++){
            ans+=solve(i);
        }
        return ans;
    }
};
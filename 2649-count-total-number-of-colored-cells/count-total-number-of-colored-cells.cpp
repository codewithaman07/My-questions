class Solution {
public:
    #define ll long long
    long long coloredCells(int n) {
        ll ans = 1;
        if(n == 1) return ans;
        for(int i = 2; i<=n; i++){
            ans+=(i-1)*4;
        }
        return ans;
    }
};
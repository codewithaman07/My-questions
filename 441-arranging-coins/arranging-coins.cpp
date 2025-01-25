class Solution {
public:
    #define ll long long
    int arrangeCoins(int n) {
        int l = 1, r = n, ans = 0;
        while(l<=r){
            ll mid = l+(r-l)/2;
            ll temp = mid*(mid+1)/2;
            if(temp <= n){
                l = mid+1;
                ans = mid;
            }
            else r = mid-1;
        }
        return ans;
    }
};
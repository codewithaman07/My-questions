class Solution {
public:
    #define ll long long
    int mySqrt(int x) {
        if(x == 0 || x == 1) return x;
        int l = 1, r = x;
        while(l<=r){
            ll mid = l+(r-l)/2;
            ll temp = mid*mid;
            if(temp == x) return (int)mid;
            else if(temp>x) r = mid-1;
            else l = mid+1;
        }
        return r;
    }
};
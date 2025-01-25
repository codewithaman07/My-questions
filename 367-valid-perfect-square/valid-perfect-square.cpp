class Solution {
public:
    #define ll long long
    bool isPerfectSquare(int num) {
        int l = 1, r = num;
        while(l<=r){
            ll mid = l+(r-l)/2;
            ll temp = mid*mid;
            if(num == temp) return 1;
            else if(temp > num) r = mid-1;
            else l = mid+1;
        }
        return 0;
    }
};
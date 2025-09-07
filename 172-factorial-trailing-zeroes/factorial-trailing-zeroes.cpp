class Solution {
public:
    int trailingZeroes(int n) {
        int temp = 5, ans = 0;
        while(temp<=n){
            ans += n/temp;
            temp*=5;
        }
        return ans;
    }
};
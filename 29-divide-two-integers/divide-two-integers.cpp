class Solution {
public:
    int divide(int dividend, int divisor) {
        int sign = (dividend<0)^(divisor<0);
        long long absDivisor = labs(divisor);
        long long absDividend = labs(dividend);
        int ans = 0;
        if (dividend == INT_MIN && divisor == -1) return INT_MAX; 
        if (dividend == INT_MIN && divisor == 1) return INT_MIN; 
        while(absDividend >= absDivisor){
            long long temp = absDivisor, mul = 1;
            while(absDividend >= (temp<<1)){
                temp<<=1;
                mul<<=1;
            }
            absDividend-=temp;
            ans+=mul;
        }
        return sign == 1 ? -ans : ans; 
    }
};
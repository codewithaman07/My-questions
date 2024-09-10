class Solution {
public:
    double pow(double x, int n){
        if(n == 0) return 1;
        double temp = pow(x,n/2);
        if(n&1) return temp*temp*x;
        return temp*temp;
    }
    double myPow(double x, int n) {
        double ans = n > 0 ? pow(x,n) : pow(1/x,n);
        return ans;
    }
};
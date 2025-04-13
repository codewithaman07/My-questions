class Solution {
public:
    #define ll long long
    int M = 1e9+7;
    ll pow(ll x, ll y){
        if(y == 0) return 1;
        ll temp = pow(x, y/2)%M;
        temp = (temp*temp)%M;
        if(y&1) return (x*temp)%M;
        return temp;
    }
    int countGoodNumbers(long long n) {
        ll odd = n/2, even = (n+1)/2;
        ll a = pow(4,odd)%M;
        ll b = pow(5,even)%M;
        return (a*b)%M;
    }
};
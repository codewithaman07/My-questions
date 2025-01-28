class Solution {
public:
    #define ll long long
    const int M = 1e9+7;
    ll pow(ll x, ll n){
        if(n == 0) return 1ll;
        ll temp = pow(x,n/2)%M;
        temp = (temp * temp) % M;
        if(n&1) return (temp * x % M) % M;
        return temp;
    }
    int countGoodNumbers(long long n) {
        ll odd = n/2, even = (n+1)/2;
        ll a = pow(5,even)%M;
        ll b = pow(4,odd)%M;
        return (int)((a*b)%M);
    }
};
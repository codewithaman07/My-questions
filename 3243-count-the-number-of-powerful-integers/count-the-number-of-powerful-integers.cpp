class Solution {
public:
    #define ll long long 
    ll pow(ll x, ll y){
        if(y == 0) return 1;
        ll temp = pow(x, y/2);
        temp*=temp;
        if(y&1) return x*temp;
        return temp;
    }
    ll solve(ll num, ll limit, string &s){
        string t = to_string(num);
        if(t.size()<s.size()) return 0;
        ll cnt = 0, len = t.size()-s.size();
        string temp = t.substr(len);
        for(int i = 0; i<len; i++){
            int digit = t[i]-'0';
            if(digit<=limit) cnt+= digit* pow(limit+1, len-i-1);
            else {
                cnt+=pow(limit+1, len-i);
                return cnt;
            }
        }
        if(temp>=s) cnt++;
        return cnt;
    }
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        return solve(finish, limit, s)-solve(start-1, limit, s);
    }
};
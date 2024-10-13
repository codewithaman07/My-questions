class Solution {
public:
    #define ll long long
    static bool cmp(pair<ll,ll>&a, pair<ll,ll>&b){
        double x = (double)a.first/(double)a.second;
        double y = (double)b.first/(double)b.second;
        return x>y;
    }
    long long minDamage(int power, vector<int>& damage, vector<int>& health) {
        int n = damage.size();
        ll total = accumulate(damage.begin(), damage.end(), 0);
        vector<pair<ll,ll>>arr;
        for(int i = 0; i<n; i++){
            int x = health[i];
            int temp;
            if(x%power == 0) temp = x/power;
            else temp = (x/power)+1;
            arr.push_back({damage[i], temp});
        }
        sort(arr.begin(), arr.end(), cmp);
        ll ans = 0;
        for(auto &it : arr){
            ans+=(total*it.second);
            total-=it.first;
        }
        return ans;
    }
};
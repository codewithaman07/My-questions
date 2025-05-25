class Solution {
public:
    #define ll long long
    bool fun(ll n){
        if(n<2) return 0;
        if(n == 2) return 1;
        if(n%2 == 0) return 0;
        for(ll i = 3; i*i<=n; i+=2){
            if(n%i == 0) return 0;
        }
        return 1;
    }
    long long sumOfLargestPrimes(string s) {
        int n = s.size();
        vector<ll>nums;
        for(int i = 0; i<n; i++){
            for(int j = i; j<n; j++){
                string temp = s.substr(i, j-i+1);
                ll num = stoll(temp);
                auto it = find(nums.begin(), nums.end(), num);
                if(fun(num) && it == nums.end()) nums.push_back(num);
            }
        }
        sort(nums.begin(),nums.end(), greater<>());
        ll ans = 0;
        if(nums.size()<=3) ans = accumulate(nums.begin(), nums.end(), 0ll); 
        else{
            ans+=(nums[0]);
            ans+=(nums[1]);
            ans+=(nums[2]);
        }
        return ans;
    }
};
class Solution {
public:
    #define ll long long
    ll callcm(vector<int>&nums){
        ll ans = nums[0];
        for(int i = 1; i<nums.size(); i++){
            ans = (ans*nums[i])/(__gcd(ans,(1ll*nums[i])));
        }
        return ans;
    }
    ll calgcd(vector<int>&nums){
        ll ans = nums[0];
        for(int i = 1; i<nums.size(); i++){
            ans = __gcd(ans,1ll*nums[i]);
        }
        return ans;
    }
    long long maxScore(vector<int>& nums) {
        int n = nums.size();
        ll ans = 0;
        ll gcdval = calgcd(nums);
        ll lcmval = callcm(nums);
        ans = max(ans, (gcdval*lcmval));
        for(int i = 0; i<n; i++){
            vector<int>temp;
            for(int j = 0; j<n; j++){
                if(i != j){
                    temp.push_back(nums[j]);
                }
            }
            if(!temp.empty()){
                ll x = calgcd(temp);
                ll y = callcm(temp);
                ans = max(ans, x*y);
            }
        }
        return ans;
    }
};
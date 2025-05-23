class Solution {
public:
    typedef long long ll;
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        ll sum = 0;
        int cnt = 0;
        int mini = INT_MAX;
        for(ll num : nums){
            if((num^k) > num){
                sum+=(num^k);
                cnt++;
            } 
            else sum+=num;
            mini = min((ll)mini, abs(num - (num^k)));
        }
        if(cnt%2 == 0) return sum;
        return sum - mini;
    }
};
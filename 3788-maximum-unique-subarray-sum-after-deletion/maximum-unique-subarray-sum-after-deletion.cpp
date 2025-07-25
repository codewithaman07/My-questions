class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int num : nums){
            mp[num]++;
        }
        int ans = 0, maxi = INT_MIN, f = 0;
        for(auto &[x,y] : mp){
            if(x<0){
                maxi = max(x,maxi);
            }
            if(x>=0){
                ans+=x;
                f = 1;
            }
        }
        if(f) return ans;
        return maxi;
    }
};
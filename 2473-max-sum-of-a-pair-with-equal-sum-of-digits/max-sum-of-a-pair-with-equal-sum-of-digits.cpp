class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int n = nums.size();
        map<int,priority_queue<int>>mp;
        for(int i = 0; i<n; i++){
            string s = to_string(nums[i]);
            int temp = 0;
            for(int i = 0; i<s.size(); i++){
                temp+=(s[i]-'0');
            }
            mp[temp].push(nums[i]);
        }
        int maxi = -1;
        for(auto &[x,y] : mp){
            if(y.size() < 2) continue;
            int a = y.top(); y.pop();
            int b = y.top(); y.pop();
            maxi = max(maxi, a+b);
        }
        return maxi;
    }
};
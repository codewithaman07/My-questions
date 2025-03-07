class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        int n = nums.size();
        map<int,int>mp;
        int ans = 1;
        for(int num : nums) mp[num]++;
        for(auto &[x,y] : mp){
            long long num = x;
            int cnt = 0;
            while(mp.count(num) && num<=100000){
                cnt++;
                num*=num;
            }
            ans = max(ans,cnt);
        }
        return (ans>=2) ? ans : -1;
    }
};
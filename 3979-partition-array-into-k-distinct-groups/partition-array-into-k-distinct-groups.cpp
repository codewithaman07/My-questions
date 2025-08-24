class Solution {
public:
    bool partitionArray(vector<int>& nums, int k) {
        int n = nums.size();
        if(n%k) return 0;
        int num = n/k;
        unordered_map<int,int>mp;
        for(int i = 0; i<n; i++) mp[nums[i]]++;
        for(auto &[x,y] : mp){
            if(y>num) return 0;
        }
        return 1;
    }
};
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if(arr.empty()) return {};
        unordered_map<int,int>mp;
        int n = arr.size();
        vector<int>nums = arr;
        sort(nums.begin(), nums.end());
        int rank = 1;
        mp[nums[0]] = rank;
        for(int i = 1; i<n; i++){
            if(nums[i] == nums[i-1]) continue;
            else rank++;
            mp[nums[i]] = rank;
        }
        for(auto &it : arr){
            it = mp[it];
        }
        return arr;
    }
};
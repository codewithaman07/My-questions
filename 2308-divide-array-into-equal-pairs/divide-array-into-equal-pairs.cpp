class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int num : nums){
            mp[num]++;
        }
        for(auto &[x,y] : mp){
            if(y&1) return 0;
        }
        return 1;
    }
};
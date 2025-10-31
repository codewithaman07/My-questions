class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        unordered_map<int,int>mp;
        vector<int>ans;
        for(int num : nums){
            mp[num]++;
        }
        for(auto &[x,y] : mp){
            if(y>1) ans.push_back(x);
        }
        return ans;
    }
};
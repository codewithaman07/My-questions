class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if(k<0) return 0;
        map<int,int>mp;
        int cnt = 0;
        for(int num : nums) mp[num]++;
        for(auto &it: mp){
            if(k == 0){
                if(it.second > 1) cnt++;
            }
            else{
                if(mp.find(it.first+k) != mp.end()) cnt++;
            }
        }
        return cnt;
    }
};
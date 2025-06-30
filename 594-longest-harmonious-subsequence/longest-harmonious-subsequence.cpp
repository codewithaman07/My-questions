class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int,int>mp;
        for(int num : nums) mp[num]++;
        int ans = 0;
        while(!mp.empty()){
            auto it = mp.begin();
            int x = it->first, a = it->second;
            if(next(it) != mp.end()){
                auto sec = next(it);
                int y = sec->first, b = sec->second;
                if(y-x<=1) ans = max(ans, a+b);
            }
            mp.erase(it);
        }
        return ans;
    }
};
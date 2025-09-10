class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        map<int,int>mp,prefix;
        int n = people.size();
        vector<int>ans(n,0);
        for(auto num : flowers){
            mp[num[0]]++;
            mp[num[1]+1]--;
        }
        int cnt = 0;
        for(auto &[x,y] : mp){
            cnt+=y;
            prefix[x] = cnt;
        }
        int pos = 0;
        for(int day : people){
            auto it = prefix.upper_bound(day);
            if(it == prefix.begin()){
                pos++;
                continue;
            }
            else{
                it--;
                ans[pos++] = it->second;
            }
        }
        return ans;
    }
};
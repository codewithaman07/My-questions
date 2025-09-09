class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>ans;
        int sz = intervals.size();
        map<int,int>mp;
        mp[newInterval[0]]++;
        mp[newInterval[1]]--;
        for(int idx = 0; idx < sz; idx++){
            int start = intervals[idx][0];
            int end = intervals[idx][1];
            mp[start]++;
            mp[end]--;
        }
        int cnt = 0;
        int start;
        for(auto &[x,y] : mp){
            if(cnt == 0) start = x;
            cnt+=y;
            if(cnt == 0) ans.push_back({start, x});
        }
        return ans;
    }
};
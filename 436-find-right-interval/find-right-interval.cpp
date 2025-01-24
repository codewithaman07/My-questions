class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<pair<int,int>>one(n);
        vector<int>ans(n), two(n);
        for(int i = 0; i<n; i++) one[i] = {intervals[i][0], i};
        for(int i = 0; i<n; i++) two[i] = intervals[i][1];
        sort(one.begin(),one.end());
        for(int i = 0; i<n; i++){
            auto target = make_pair(two[i], INT_MIN);
            int idx = lower_bound(one.begin(), one.end(), target)-one.begin();
            if(idx == n) ans[i] = -1;
            else ans[i] = one[idx].second;
        }
        return ans;
    }
};
class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int>&a, vector<int>&b){
            if(a[0] == b[0]) return a[1] > b[1];
            else return a[0] < b[0];
        });
        int cnt = 0, n = intervals.size(), prev = intervals[0][1];
        for(int i = 1; i<n; i++){
            if(prev >= intervals[i][1]) cnt++;
            else prev = intervals[i][1];
        }
        return n-cnt;
    }
};
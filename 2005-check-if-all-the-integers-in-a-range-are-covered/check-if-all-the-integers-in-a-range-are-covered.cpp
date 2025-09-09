class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        vector<int>cover(right+2,0);
        for(auto intervals : ranges){
            int start = intervals[0];
            int end = intervals[1];
            if(start<=right) cover[start]++;
            if(end<=right) cover[end+1]--;
        }
        int sz = cover.size();
        for(int idx = 1; idx<sz; idx++){
            cover[idx] = cover[idx]+cover[idx-1];
        }
        for(int idx = left; idx<=right; idx++){
            if(cover[idx] <= 0) return false;
        }
        return true;
    }
};
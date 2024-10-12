class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<pair<int,int>>vec;
        for(auto it : intervals){
            vec.push_back({it[0], 1});
            vec.push_back({it[1], -1});
        }
        sort(vec.begin(), vec.end(), [](const pair<int,int>&a, const pair<int,int>&b){
            if(a.first == b.first) return a.second > b.second;
            return a.first < b.first;
        });
        int maxi = 0, curr = 0;
        for(auto it : vec){
            curr+=it.second;
            maxi = max(maxi, curr);
        }
        return maxi;
    }
};
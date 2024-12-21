class Solution {
public:
    vector<vector<int>>fun(vector<vector<int>>&vec){
        int n = vec.size();
        if(n <= 1) return vec;
        sort(vec.begin(), vec.end());
        vector<vector<int>>ans;
        for(int i = 0; i<n; i++){
            if(ans.empty() || ans.back()[1] <= vec[i][0]) ans.push_back(vec[i]);
            else ans.back()[1] = max(ans.back()[1], vec[i][1]);
        }
        return ans;
    }
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<vector<int>>vert, horz;
        for(auto it : rectangles){
            vert.push_back({it[1], it[3]});
            horz.push_back({it[0], it[2]});
        }
        vector<vector<int>>x = fun(vert);
        vector<vector<int>>y = fun(horz);
        int a = x.size(), b = y.size();
        return a >= 3 || b >= 3;
    }
};
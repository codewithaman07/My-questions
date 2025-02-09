class Solution {
public: 
    int maxEnvelopes(vector<vector<int>>& grid) {
        int n = grid.size();
        sort(grid.begin(), grid.end(), [](const vector<int>&a, const vector<int>&b){
            if(a[0] == b[0]) return a[1]>b[1];
            return a[0]<b[0];
        });
        vector<int>lis;
        for(int i = 0; i<n; i++){
            int h = grid[i][1];
            auto it = lower_bound(lis.begin(),lis.end(), h);
            if(it == lis.end()) lis.push_back(h);
            else *it = h;
        }
        return lis.size();
    }
};
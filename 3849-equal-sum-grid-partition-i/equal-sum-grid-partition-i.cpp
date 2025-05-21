class Solution {
public:
    #define ll long long
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<ll>row, col;
        for(int i = 0; i<n; i++){
            ll sum = 0;
            for(int j = 0; j<m; j++){
                sum+=grid[i][j];
            }
            row.push_back(sum);
        }
        for(int j = 0; j<m; j++){
            ll sum = 0;
            for(int i = 0; i<n; i++){
                sum+=grid[i][j];
            }
            col.push_back(sum);
        }
        ll rs = accumulate(row.begin(), row.end(), 0ll);
        ll cs = accumulate(col.begin(), col.end(), 0ll);
        if(n>1){
            ll r = 0;
            for(int i = 0; i<row.size(); i++){
                r+=row[i];
                if(r == (rs-r)) return 1;
            }
        }
        if(m>1){
            ll r = 0;
            for(int i = 0; i<col.size(); i++){
                r+=col[i];
                if(r == (cs-r)) return 1;
            }
        }
        return 0;
    }
};
class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int l = INT_MAX, r = INT_MIN, t = INT_MAX, b = INT_MIN;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){   
                if(grid[i][j] == 1){
                    l = min(l,j);
                    r = max(r,j);
                    t = min(t,i);
                    b = max(b,i);
                }
            }
        }
        int len = b-t+1;
        int wid = r-l+1;
        return (len*wid);
    }
};
class Solution {
public:
    int findChampion(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int>cnt(2*n,0);
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j]){
                    cnt[i]++;
                }
            }
        }
        int maxi = INT_MIN, ans = -1;
        for(int i = 0; i<cnt.size(); i++){
            if(cnt[i]>maxi){
                maxi = cnt[i];
                ans = i;
            }
        }
        return ans;
    }
};
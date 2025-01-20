class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<int>row(n,0), col(m,0);
        vector<pair<int,int>>grid(n*m+1);
        for(int i = 0; i<n; i++) for(int j = 0; j<m; j++) grid[mat[i][j]] = {i,j};
        for(int i = 0; i<arr.size(); i++){
            if(++row[grid[arr[i]].first] == m || ++col[grid[arr[i]].second] == n) return i;
        }
        return -1;
    }
};
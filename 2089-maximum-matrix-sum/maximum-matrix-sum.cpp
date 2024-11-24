class Solution {
public:
    #define ll long long
    long long maxMatrixSum(vector<vector<int>>& mat) {
        ll sum = 0, mini = INT_MAX, neg = 0, n = mat.size(), m = mat[0].size();
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(mat[i][j] < 0) neg++;
                mini = min(abs(mat[i][j])*1ll, mini);
                sum+= abs(mat[i][j]);
            }
        }
        if(!(neg&1)) return sum;
        return sum - 2*mini;
    }
};
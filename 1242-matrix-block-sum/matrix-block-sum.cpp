class Solution {
public:
    vector<vector<int>>presum(vector<vector<int>>&mat){
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>>pre(n+1, vector<int>(m+1,0));
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=m; j++){
                pre[i][j] = mat[i-1][j-1]+pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1];
            }
        }
        return pre;
    }
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int n = mat.size(), m = mat[0].size();  
        vector<vector<int>>pre = presum(mat);
        vector<vector<int>>ans(n, vector<int>(m,0));
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                int r1 = max(0,i-k);
                int c1 = max(0,j-k);
                int r2 = min(n-1, i+k);
                int c2 = min(m-1, j+k);
                r1++, c1++, r2++, c2++;
                ans[i][j]   = pre[r2][c2] 
                            - (r1>1 ? pre[r1-1][c2] : 0) 
                            - (c1>1 ? pre[r2][c1-1] : 0) 
                            + (r1>1 && c1>1 ? pre[r1-1][c1-1] : 0);
            }
        }
        return ans;
    }
};
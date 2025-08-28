class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        unordered_map<string,int>mp;
        for(int i = 0; i<n; i++){
            char ch = mat[i][0];
            string s;
            for(int j = 0; j<m; j++){
                if(mat[i][j] == ch) s+='s';
                else s+='c';
            }
            mp[s]++;
        }
        int ans = 0;
        for(auto [x,y] : mp){
            ans = max(ans,y);
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        map<int,vector<int>>mp;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                mp[i+j].push_back(mat[i][j]);
            }
        }
        vector<int>ans;
        bool f = 1;
        for(auto &[x,y] : mp){
            if(f){
                reverse(y.begin(), y.end());
                for(int num : y) ans.push_back(num);
            }
            else{
                for(int num : y) ans.push_back(num);
            }
            f = !f;
        }
        return ans;
    }
};
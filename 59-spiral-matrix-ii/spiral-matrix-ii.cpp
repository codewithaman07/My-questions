class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>ans(n, vector<int>(n,-1));
        int num = 1;
        int l = 0, r = n-1, t = 0, b = n-1;
        while(l<=r && t<=b){
            if(t<=b){
                for(int i = l; i<=r; i++){
                    ans[t][i] = num++;
                }
            }
            t++;
            if(l<=r){
                for(int i = t; i<=b; i++){
                    ans[i][r] = num++;
                }
            }
            r--;
            if(t<=b){
                for(int i = r; i>=l; i--){
                    ans[b][i] = num++;
                }
                b--;
            }
            if(l<=r){
                for(int i = b; i>=t; i--){
                    ans[i][l] = num++;
                }
                l++;
            }
        }
        return ans;
    }
};
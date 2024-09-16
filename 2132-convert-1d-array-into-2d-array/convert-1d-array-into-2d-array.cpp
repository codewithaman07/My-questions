class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& arr, int n, int m) {
        int x = arr.size();
        if(x!=n*m) return {};
        vector<vector<int>>ans(n,vector<int>(m));
        for(int i = 0; i<x; i++){
            ans[i/m][i%m] = arr[i];
        }
        return ans;
    }
};
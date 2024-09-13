class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int>pre(n), ans(queries.size());
        pre[0] = arr[0];
        for(int i = 1; i<n; i++){
            pre[i] = pre[i-1]^arr[i];
        }
        n = queries.size();
        for(int i = 0; i<n; i++){
            int l = queries[i][0];
            int r = queries[i][1];
            l>0 ? ans[i] = pre[r]^pre[l-1] : ans[i] = pre[r];
        }
        return ans;
    }
};
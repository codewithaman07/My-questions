class Solution {
public:
    int solve(vector<vector<int>>&mat, int val, int n, int m){
        int cnt = 0;
        for(int i = 0; i<n; i++){
            cnt+= upper_bound(mat[i].begin(), mat[i].end(), val)-mat[i].begin();
        }
        return cnt;
    }
    int kthSmallest(vector<vector<int>>& mat, int k) {
        int n = mat.size(), m = mat[0].size();
        int l = mat[0][0], r = mat[n-1][m-1], ans = -1;
        while(l<=r){
            int mid = l+(r-l)/2;
            int cnt = solve(mat,mid,n,m);
            if(cnt>=k){
                ans = mid;
                r = mid-1;
            }
            else l = mid+1;
        }
        return ans;
    }
};
class Solution {
public:
    bool fun(int n, int m, int k, int mid){
        int cnt = 0;
        for(int i = 1; i<=n; i++){
            cnt+= min(mid/i, m);
        }
        return cnt<k;
    }
    int findKthNumber(int n, int m, int k) {
        int l = 1, r = n*m;
        while(l<r){
            int mid = l+(r-l)/2;
            if(fun(n,m,k,mid)) l = mid+1;
            else r = mid;
        }
        return l;
    }
};
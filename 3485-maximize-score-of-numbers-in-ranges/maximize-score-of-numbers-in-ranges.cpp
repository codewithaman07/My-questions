class Solution {
public:
#define ll long long
    bool check(int mid, vector<int>start, int d){
        for(int i = 1; i<start.size(); i++){
            if(start[i]-start[i-1] >= mid) continue;
            else{
                if(start[i]+d - start[i-1] < mid) return false;
                start[i] = start[i-1]+mid;
            }
        }
        return true;
    }
    int maxPossibleScore(vector<int>& start, int d) {
        sort(start.begin(), start.end());
        ll n = start.size();
        ll l = 0, r = 2e9+1, ans = 0;
        while(l<=r){
            int m = (l+r)>>1;
            if(check(m, start,d)){
                ans = m;
                l = m+1;
            }
            else r = m-1;
        }
        return ans;
    }
};
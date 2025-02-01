class Solution {
public:
    int maxFreeTime(int t, vector<int>& start, vector<int>& end) {
        int n = start.size();
        vector<int>gaps;
        int prev = 0;
        for(int i = 0; i<n; i++){
            gaps.push_back(start[i]-prev);
            prev = end[i];
        }
        gaps.push_back(t-end.back());
        n = gaps.size();
        vector<int> pre(n, 0), suf(n,0);
        for(int i = 1; i<n; i++){
            pre[i] = max(pre[i-1], gaps[i-1]);
        }
        for(int i = n-2; i>=0; i--){
            suf[i] = max(suf[i+1], gaps[i+1]);
        }
        int maxi = *max_element(gaps.begin(), gaps.end());
        n = start.size();
        for(int i = 0; i<n; i++){
            int temp = end[i]-start[i];
            int l = gaps[i];
            int r = gaps[i+1];
            maxi = max(maxi, l+r);
            if(max(pre[i], suf[i+1]) >= temp){
                maxi = max(maxi, l+r+temp);
            }
        }
        return maxi;
    }
};
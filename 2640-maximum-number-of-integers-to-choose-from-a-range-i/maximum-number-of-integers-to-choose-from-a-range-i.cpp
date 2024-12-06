class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int>st(banned.begin(), banned.end());
        int cnt = 0, sum = 0;
        for(int i = 1; i<=n; i++){
            if(st.count(i)) continue;
            if(sum+i > maxSum) break;
            sum+=i;
            cnt++;
        }
        return cnt;
    }
};
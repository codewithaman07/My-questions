class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& cost) {
        // mininmum cost to travel all n days 
        // dp max size 365 parameter index  
        // base case dp[0] = 0;
        // dp flow 1 to n 
        int n = days[days.size()-1], x = cost[0], y = cost[1], z = cost[2];
        vector<int>dp(n+1, 0);
        unordered_set<int>st(days.begin(), days.end());
        for(int i = 1; i<=n; i++){
            if(st.find(i) == st.end()) dp[i] = dp[i-1];
            else dp[i] = min({dp[i-1]+x, dp[max(0, i-7)]+y, dp[max(0,i-30)]+z});
        }
        return dp[n];
    }
};
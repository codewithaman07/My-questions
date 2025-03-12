class Solution {
public:
    int dp[201][201];
    int solve(int n, int k, int city, int day, vector<vector<int>>&stay, vector<vector<int>>&travel){
        if(day>=k) return 0;
        if(dp[day][city] != -1) return dp[day][city];
        int ans = stay[day][city]+solve(n,k,city, day+1, stay, travel);
        for(int j = 0; j<n; j++){
            ans = max(ans, travel[city][j]+solve(n,k,j,day+1,stay,travel));
        }
        return dp[day][city] = ans;
    }
    int maxScore(int n, int k, vector<vector<int>>& stayScore, vector<vector<int>>& travelScore) {
        memset(dp, -1, sizeof(dp));
        int ans = 0;
        for(int i = 0; i<n; i++){
            ans = max(ans, solve(n,k,i,0,stayScore, travelScore));
        }
        return ans;
    }
};
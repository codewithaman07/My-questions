class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());
        int n = meetings.size(), ans = 0;
        ans+=(meetings[0][0]-1);
        for(int i = 1; i<n; i++){
            if(meetings[i][0]<=meetings[i-1][1]){
                meetings[i][1] = max(meetings[i-1][1], meetings[i][1]);
            }
            else ans+=(meetings[i][0]-meetings[i-1][1]-1);
        }
        ans+=(days-meetings[n-1][1]);
        return ans;
    }
};
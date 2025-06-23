class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        map<int,int>mp;
        int n = logs.size(), ans = INT_MAX, cnt = 0, maxi = 0;
        for(int i = 0; i<n; i++){
            mp[logs[i][0]]++;
            mp[logs[i][1]]--;
        }
        for(auto &[x,y] : mp){
            cnt+=y;
            if(cnt>maxi){
                maxi = cnt;
                ans = x;
            }
        }
        return ans;
    }
};
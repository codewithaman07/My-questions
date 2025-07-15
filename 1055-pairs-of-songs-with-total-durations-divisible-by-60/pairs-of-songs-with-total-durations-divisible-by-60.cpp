class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int n = time.size(), ans = 0;
        for(int &num : time) num%=60;
        unordered_map<int,int>mp;
        for(int i = 0; i<n; i++){
            if(mp.count(60-time[i])) ans+=(mp[60-time[i]]);
            mp[time[i]]++;
        }
        for(int num : time) cout<<num<<" ";
        return ans+(1ll*mp[0]*(mp[0]-1))/2;
    }
};
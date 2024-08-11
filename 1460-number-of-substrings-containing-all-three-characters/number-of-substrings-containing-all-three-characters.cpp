class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int>v(3,-1);
        int n = s.size(), ans = 0;
        for(int i = 0; i<n; i++){
            v[s[i]-'a'] = i;
            if((v[0] != -1) && (v[1] != -1) && (v[2] != -1)){
                int mini = min({v[0],v[1],v[2]});
                ans = ans+mini+1;
            }
        }
        return ans;
    }
};
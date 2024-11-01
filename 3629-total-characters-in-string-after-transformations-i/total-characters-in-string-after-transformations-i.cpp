class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        int mod = 1e9+7;
        vector<int>cnt(26,0);
        for(char &ch : s) cnt[ch-'a']++;
        for(int j = 0; j<t; j++){
            vector<int>temp(26,0);
            for(int i = 0; i<26; i++){
                if(i == 25){
                    temp[0] = (temp[0]+cnt[i])%mod;
                    temp[1] = (temp[1]+cnt[i])%mod;
                }
                else temp[i+1] = (temp[i+1]+cnt[i])%mod;
            }
            cnt = temp;
        }
        int ans = 0;
        for(auto i : cnt){
            ans = (ans+i)%mod;
        }
        return ans;
    }
};
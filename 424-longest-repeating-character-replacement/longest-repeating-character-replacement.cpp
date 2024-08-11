class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0, r = 0, n = s.size(), freq = 0, maxi = 0;
        vector<int>hash(26,0);
        while(r<n){
            hash[s[r]-'A']++;
            freq = max(freq, hash[s[r]-'A']);
            if((r-l+1)-freq >k){
                hash[s[l]-'A']--;
                l++;
            }
            if((r-l+1)-freq<=k){
                maxi = max(maxi, (r-l+1));
            }
            r++;
        }
        return maxi;
    }
};
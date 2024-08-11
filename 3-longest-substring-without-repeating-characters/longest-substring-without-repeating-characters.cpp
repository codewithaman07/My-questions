class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int l = 0, r = 0, maxi = 0, len = 0;
        int hash[256];
        memset(hash, -1, sizeof(hash));
        while(r<n){
            if(hash[s[r]] != -1 && hash[s[r]]>=l){
                l = hash[s[r]]+1;
            }
            hash[s[r]] = r;
            len = r-l+1;
            maxi = max(len, maxi);
            r++;
        }
        return maxi;
    }
};
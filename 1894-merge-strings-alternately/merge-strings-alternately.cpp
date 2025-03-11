class Solution {
public:
    string mergeAlternately(string s, string t) {
        string ans;
        int n = s.size(), m = t.size(), i = 0, j = 0;
        while(i<n && j<m){
            ans+=s[i++];
            ans+=t[j++];
        }
        while(i<n) ans+=s[i++];
        while(j<m) ans+=t[j++];
        return ans;
    }
};
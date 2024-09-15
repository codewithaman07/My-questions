class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        string t;
        int ans = 0;
        for(int i = 0; i<n; i++){
            auto x = t.find(s[i]);
            if(x != string::npos) t = t.substr(x+1);
            t+=s[i];
            ans = max(ans, (int)t.size());
        }
        return ans;
    }
};
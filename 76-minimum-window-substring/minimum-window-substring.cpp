class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size(), m = t.size(), cnt = 0, l = 0, r = 0, idx = -1, mini = 1e9;
        int hash[256] = {0};
        for(int i = 0; i < m; i++) hash[t[i]]++;
        while (r < n) {
            if (hash[s[r]] > 0) cnt++;
            hash[s[r]]--;
            while (cnt == m) {
                if ((r - l + 1) < mini) {
                    mini = r - l + 1;
                    idx = l;
                }
                hash[s[l]]++;
                if (hash[s[l]] > 0) cnt--;
                l++;
            }
            r++;
        }
        return (idx == -1) ? "" : s.substr(idx, mini);
    }
};

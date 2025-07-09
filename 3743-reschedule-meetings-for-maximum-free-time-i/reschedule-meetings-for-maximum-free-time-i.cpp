class Solution {
public:
    int maxFreeTime(int t, int k, vector<int>& s, vector<int>& e) {
        int n = s.size();
        vector<int> temp;
        temp.push_back(s[0] - 0);
        for (int i = 1; i < n; ++i) {
            temp.push_back(s[i] - e[i - 1]);
        }
        temp.push_back(t - e.back());
        
        int m = temp.size();
        if (k + 1 >= m) {
            return accumulate(temp.begin(), temp.end(), 0);
        }
        int curr = 0;
        for (int i = 0; i<=k; i++) {
            curr += temp[i];
        }
        
        int maxi = curr;
        for (int i = k + 1; i < m; ++i) {
            curr += temp[i] - temp[i - (k + 1)];
            maxi = max(maxi, curr);
        }
        
        return maxi;
    }
};
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int>cnt1(26,0), cnt2(26,0);
        int n = s1.size(), m = s2.size();
        if(n > m) return 0;
        for(int i = 0; i<n; i++){
            cnt1[s1[i]-'a']++;
            cnt2[s2[i]-'a']++;
        }
        if(cnt1 == cnt2) return 1;
        for(int i = n; i<m; i++){
            if(cnt1 == cnt2) return 1;
            cnt2[s2[i]-'a']++;
            cnt2[s2[i-n]-'a']--;
        } 
        return cnt1 == cnt2;
    }
};
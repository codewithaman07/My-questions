class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int cnt = 0, n = s1.size();
        vector<int>freq1(26,0), freq2(26,0);
        for(int i = 0; i<n; i++){
            if(s1[i] != s2[i]) cnt++;
            freq1[s1[i]-'a']++;
            freq2[s2[i]-'a']++;
        }
        for(int i = 0; i<26; i++){
            if(freq1[i] != freq2[i]) return 0;
        }
        if(cnt == 0 || cnt == 2) return 1;
        return 0;
    }
};
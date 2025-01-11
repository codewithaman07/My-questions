class Solution {
public:
    bool canConstruct(string s, int k) {
        vector<int>mp(26,0);
        int even = 0, odd = 0;
        for(char &ch : s) mp[ch-'a']++;
        for(int i = 0; i<26; i++){
            if(mp[i] == 0) continue;
            else if(mp[i]&1) odd++;
            else even++;
        }
        if(odd > k || k > s.size()) return 0;
        return 1;
    }
};
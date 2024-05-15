class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int hash[256] = {0};
        bool hash2[256] = {0};
        for(int i = 0; i<s.length(); i++){
            if(hash[s[i]] == 0 && hash2[t[i]] == 0){
                hash[s[i]] = t[i];
                hash2[t[i]] = true;
            }
        }
        for(int i = 0; i<s.length(); i++){
            if(char(hash[s[i]]) != t[i]){
                return false;
            }
        }
        return true;
    }
};

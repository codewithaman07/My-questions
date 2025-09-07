class Solution {
public:
    int minOperations(string s) {
        int n = s.size(), ans = 0, f = 0;
        vector<int>freq(26,0);
        for(int i = 0; i<n; i++){
            freq[s[i]-'a']++;
        }
        for(int i = 1; i<26; i++){
            if(f){
                ans++;
                continue;
            }
            if(freq[i]>0){
                f = 1;
                ans++;
            }
        }
        return ans;
    }
};
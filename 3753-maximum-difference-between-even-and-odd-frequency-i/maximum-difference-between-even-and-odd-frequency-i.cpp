class Solution {
public:
    int maxDifference(string s) {
        int n = s.size(), odd = 0, even = INT_MAX;
        vector<int>freq(26,0);
        for(char &ch : s){
            freq[ch-'a']++;
        }
        for(int i = 0; i<26; i++){
            if(freq[i]&1) odd = max(freq[i], odd);
            else{
                if(freq[i] != 0) even = min(freq[i], even);
            }
        }
        return odd-even;
    }
};
class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int>freq(26,0);
        int n = s.size();
        for(char ch : s) freq[ch-'a']++;
        int idx = -1;
        for(int i = 0; i<26; i++){
            if(freq[i]&1){
                idx = i;
                freq[i]--;
                break;
            }
        }
        string ans;
        for(int i = 0; i<26; i++){
            ans+=string(freq[i]/2, i+'a');
        }
        string x = ans;
        reverse(x.begin(), x.end());
        if(idx != -1){
            string mid = string(1,idx+'a');
            string res = ans+mid+x;
            return res;
        }
        string res = ans+x;
        return res;
    }
};
class Solution {
public:
    string robotWithString(string s) {
        string p,t;
        int n = s.size();
        vector<int>freq(26,0), temp(26,0);
        for(int i = 0; i<n; i++) freq[s[i]-'a']++;
        for(int i = 0; i<n; i++){
            p+=s[i];
            int num = s[i]-'a';
            freq[num]--;
            int j = 0;
            while(j<26 && freq[j] == 0) j++;
            while(!p.empty() && (j == 26 || p.back() <= char('a')+j)){
                t+=p.back();
                p.pop_back();
            }
        }
        while (!p.empty()) {
            t += p.back();
            p.pop_back();
        }
        return t;
    }
};
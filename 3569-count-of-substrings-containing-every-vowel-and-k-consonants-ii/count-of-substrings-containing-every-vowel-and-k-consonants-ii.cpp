class Solution {
public:
    #define ll long long 
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    long long countOfSubstrings(string s, int k) {
        int l = 0, n = s.size();
        ll cnt = 0, temp = 0;
        vector<int>cons(n);
        int idx = n;
        unordered_map<char,int>mp;
        for(int i = n-1; i>=0; i--){
            cons[i] = idx;
            if(!isVowel(s[i])) idx = i;
        }
        for(int r = 0; r<n; r++){
            char ch = s[r];
            if(isVowel(ch)) mp[ch]++;
            else temp++;
            while(temp > k) {
                char ch = s[l];
                if(isVowel(ch)) {
                    mp[ch]--;
                    if(mp[ch] == 0)
                        mp.erase(ch);
                } else {
                    temp--;
                }
                l++;
            }
            while(l<n && mp.size() == 5 && temp == k){
                int idx = cons[r];
                cnt+=(idx-r);
                char ch = s[l];
                if(!isVowel(ch)) temp--;
                else{
                    if(--mp[ch] == 0) mp.erase(ch);
                }
                l++;
            }
        }
        return cnt;
    }
};
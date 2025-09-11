class Solution {
public:
    bool isVowel(char &ch){
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') return true;
        return false;
    }
    string sortVowels(string s) {
        unordered_map<char,int>mp;
        string sorted = "AEIOUaeiou", ans;
        for(char &ch : s){
            if(isVowel(ch)) mp[ch]++;
        }
        int pos = 0;
        for(char &ch : s){
            if(isVowel(ch)){
                while(mp[sorted[pos]] == 0) pos++;
                ans+=sorted[pos];
                mp[sorted[pos]]--;
            }
            else ans+=ch;
        }
        return ans;
    }
};
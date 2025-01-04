class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_set<char>chars;
        for(char &ch : s) chars.insert(ch);
        int ans = 0, n = s.size();
        for(char ch : chars){
            int i = -1, j = 0;
            for(int k = 0; k<n; k++){
                if(s[k] == ch){
                    if(i == -1) i = k;
                    j = k;
                }
            }
            unordered_set<char>st;
            for(int k = i+1; k<j; k++){
                st.insert(s[k]);
            }
            ans+=st.size();
        }
        return ans;
    }
};
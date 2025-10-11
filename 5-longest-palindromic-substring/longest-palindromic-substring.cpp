class Solution {
public:
    bool ispalindrome(string& s, int i , int j){
        while(i<j){
            if(s[i] != s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    string longestPalindrome(string s) {
        int n = s.length();
        string ans = "";
        for(int i = 0; i<n; i++){
            for(int j = i; j<n; j++){
                if((j-i+1 > ans.size()) && ispalindrome(s, i, j)){
                    string t = s.substr(i, j-i+1);
                    ans = t;
                }
            }
        }
        return ans;
    }
};
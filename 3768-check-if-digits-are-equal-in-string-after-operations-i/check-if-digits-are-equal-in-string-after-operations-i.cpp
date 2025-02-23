class Solution {
public:
    bool hasSameDigits(string s) {
        int n = s.size();
        while(s.size() > 2){
            for(int i = 1; i<n; i++){
                int num = ((s[i-1]-'0')+(s[i]-'0'))%10;
                s[i-1] = char(num);
            }
            s.erase(s.end()-1);
        }
        return s[0] == s[1];
    }
};
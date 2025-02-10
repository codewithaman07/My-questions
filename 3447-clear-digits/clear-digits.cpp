class Solution {
public:
    string clearDigits(string s) {
        for(int i = 0; i<s.size(); i++){
            if(isdigit(s[i])){
                if(i>0) s.erase(i-1,2);
                else s.erase(i,1);
                return clearDigits(s);
            }
        }
        return s;
    }
};
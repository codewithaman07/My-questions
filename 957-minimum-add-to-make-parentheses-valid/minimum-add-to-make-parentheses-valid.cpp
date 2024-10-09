class Solution {
public:
    int minAddToMakeValid(string s) {
        int num = 0, cnt = 0, n = s.size();
        for(int i = 0; i<n; i++){
            if(s[i] == '(') num++;
            else {
                if(num == 0) cnt++;
                else num--;
            }
        }
        return num+cnt;
    }
};
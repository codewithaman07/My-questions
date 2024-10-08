class Solution {
public:
    int minAddToMakeValid(string s) {
        int cnt = 0, num = 0;
        for(char &ch : s){
            if(ch == '(') num++;
            else{
                if(num == 0) cnt++;
                else num--;
            }
        }
        return num == 0 ? cnt : num+cnt;
    }
};
class Solution {
public:
    string largestGoodInteger(string num) {
        int n = num.size(), cnt = 1, f = 0;
        char ch = num[0], temp;
        for(int i = 1; i<n; i++){
            if(num[i] == ch) cnt++;
            else{
                cnt = 1;
                ch = num[i];
            }
            if(cnt>=3) temp = max(temp, num[i]), f = 1;
        }
        if(!f) return "";
        string ans = string(3,temp);
        return ans;
    }
};
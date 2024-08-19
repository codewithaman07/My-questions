class Solution {
public:
    string convertToTitle(int num) {
        string ans;
        while(num){
            num--;
            int temp = (num%26)+65;
            ans = (char)(temp)+ans;
            num/=26;
        }
        return ans;
    }
};
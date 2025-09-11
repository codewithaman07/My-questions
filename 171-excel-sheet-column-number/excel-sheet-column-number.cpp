class Solution {
public:
    int titleToNumber(string columnTitle) {
        int n = columnTitle.size();
        int ans = 0;
        for(char c : columnTitle){
            int num = c-'A'+1;
            ans = ans*26+num;
        }
        return ans;
    }
};
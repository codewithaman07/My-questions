class Solution {
public:
    string stringHash(string s, int k) {
        string res;
        int n = s.size();
        int r = 0;
        int temp = 0;
        for(int r = 1; r<=n; r++){
            temp+=(s[r-1]-'a');
            if(r%k == 0){
                res+=((temp%26)+'a');
                temp = 0;
            }
        }
        return res;
    }
};
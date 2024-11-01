class Solution {
public:
    string makeFancyString(string s) {
        int n = s.size(), j = 2;
        if(n<3) return s;
        for(int i = 2; i<n; i++){
            if(s[i] != s[j-1] || s[i] != s[j-2]){
                s[j++] = s[i];
            }
        }
        s.resize(j);
        return s;
    }
};
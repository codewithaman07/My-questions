class Solution {
public:
    string makeFancyString(string s) {
        int n = s.size(), freq = 1;
        char prev = s[0];
        string ans;
        ans+=s[0];
        for(int i = 1; i<n; i++){
            if(s[i] == prev) freq++;
            else{
                prev = s[i];
                freq = 1;
            }
            if(freq<3) ans+=s[i];
        }
        return ans;
    }
};

// class Solution {
// public:
//     string makeFancyString(string s) {
//         int n = s.size(), j = 2;
//         if(n<3) return s;
//         for(int i = 2; i<n; i++){
//             if(s[i] != s[j-1] || s[i] != s[j-2]){
//                 s[j++] = s[i];
//             }
//         }
//         s.resize(j);
//         return s;
//     }
// };
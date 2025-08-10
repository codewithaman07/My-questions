class Solution {
public:
    string breakPalindrome(string s) {
        int n = s.size();
        if(n == 1) return "";
        for(int i = 0; i<n/2; i++){
            if(s[i] != 'a'){
                s[i] = 'a';
                return s;
            }
        }
        s[n-1] = 'b';
        return s;
    }
};

// class Solution {
// public:
//     bool pal(string &s){
//         int l = 0, r = s.size()-1;
//         while(l<r){
//             if(s[l++] != s[r--]) return 0;
//         }
//         return 1;
//     }
//     string breakPalindrome(string s) {
//         int n = s.size();
//         if(n == 1) return "";
//         string best;
//         for(int i = 0; i<n; i++){
//             char temp = s[i];
//             for(char ch = 'a'; ch<='z'; ch++){
//                 if(ch == temp) continue;
//                 s[i] = ch;
//                 if(!pal(s)){
//                     if(best.empty() || s < best) best = s;
//                 }
//             }
//             s[i] = temp;
//         }
//         return best;
//     }
// };
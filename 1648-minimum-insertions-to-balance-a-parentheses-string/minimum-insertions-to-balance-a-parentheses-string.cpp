class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        int ans = 0, num = 0;
        for(int i = 0; i<n; i++){
            if(s[i] == '(') num++;
            else{
                if(i+1< n && s[i+1] == ')'){
                    if(num == 0) ans++;
                    else num--;
                    i++;
                }
                else{
                    if(num == 0) ans+=2;
                    else ans++, num--;
                }
            }
        }
        if(num!=0){
            ans+=(num*2);
        }
        return ans;
    }
};

// class Solution {
// public:
//     int minInsertions(string s) {
//         stack<char>st;
//         int n = s.size();
//         int ans = 0;
//         for(int i = 0; i<n; i++){
//             if(s[i] == '(') st.push(s[i]);
//             else{
//                 if(i+1< n && s[i+1] == ')'){
//                     if(st.empty()) ans++;
//                     else st.pop();
//                     i++;
//                 }
//                 else{
//                     if(st.empty()) ans+=2;
//                     else ans++, st.pop();
//                 }
//             }
//         }
//         if(!st.empty()){
//             ans+=(st.size()*2);
//         }
//         return ans;
//     }
// };
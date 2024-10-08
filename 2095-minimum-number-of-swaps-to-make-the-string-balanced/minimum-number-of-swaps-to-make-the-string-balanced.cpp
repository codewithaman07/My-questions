class Solution {
public:
    int minSwaps(string s) {
        int n = s.size();
        int cnt = 0;
        stack<char>st;
        for(int i = 0; i<n; i++){
            if(s[i] == '[') st.push(s[i]);
            else{
                if(st.empty()) cnt++;
                else st.pop();
            }
        }
        return (cnt+1)/2;
    }
};
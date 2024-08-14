class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char>st, ts;
        int n = s.size(), m = t.size();
        for(int i = 0; i<n; i++){
            if(s[i] != '#') st.push(s[i]);
            else if(!st.empty()) st.pop();
        }
        for(int i = 0; i<m; i++){
            if(t[i] != '#') ts.push(t[i]);
            else if(!ts.empty()) ts.pop();
        }
        while(!st.empty() && !ts.empty()) {
            if(st.top() != ts.top()) {
                return false;
            }
            st.pop();
            ts.pop();
        }
        return st.empty() && ts.empty();
    }
};
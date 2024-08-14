class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char>st, ts;
        string s1,t1;
        int n = s.size(), m = t.size();
        for(int i = 0; i<n; i++){
            if(s[i] != '#') st.push(s[i]);
            else if(!st.empty()) st.pop();
        }
        for(int i = 0; i<m; i++){
            if(t[i] != '#') ts.push(t[i]);
            else if(!ts.empty()) ts.pop();
        }
        while(!st.empty()){
            s1+=st.top();
            st.pop();
        }
        while(!ts.empty()){
            t1+=ts.top();
            ts.pop();
        }
        cout<<s1<<" "<<t1;
        return s1 == t1;
    }
};
class Solution {
public:
    string smallestNumber(string pattern) {
        string num;
        int cnt = 1, n = pattern.size();
        stack<char>st;
        for(int i = 0; i<=n; i++){
            if(pattern[i] == 'I'){
                st.push(cnt+'0');
                cnt++;
                while(!st.empty()){
                    num.push_back(st.top());
                    st.pop();
                }
            }
            else{
                st.push(cnt+'0');
                cnt++;
            }
        }
        while(!st.empty()){
            num.push_back(st.top());
            st.pop();
        }
        return num;
    }
};
class Solution {
public:
    int calculate(string s) {
        stack<int>st;
        int n = s.size(), num = 0;
        char sign = '+';
        for(int i = 0; i<n; i++){
            if(isdigit(s[i])) num = num*10 + (s[i]-'0');
            if(!isdigit(s[i]) && s[i] != ' ' || i == n-1){
                if(sign == '+') st.push(num);
                else if(sign == '-') st.push(-num);
                else if(sign == '*'){
                    int temp = st.top(); st.pop();
                    st.push(temp*num);
                }
                else if(sign == '/'){
                    int temp = st.top(); st.pop();
                    st.push(temp/num);
                }
                num = 0;
                sign = s[i];
            }
            
        }
        int ans = 0;
        while(!st.empty()){
            ans+=(st.top());
            st.pop();
        }
        return ans;
    }
};
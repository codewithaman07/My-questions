class Solution {
public:
    int calculate(string s) {
        int n = s.size(), ans = 0, num = 0, sign = 1;
        stack<int>st;
        for(int i = 0; i<n; i++){
            if(isdigit(s[i])) num = (num*10)+(s[i]-'0');
            else if(s[i] == '+'){
                ans+=(num*sign);
                num = 0, sign = 1;
            }
            else if(s[i] == '-'){
                ans+=(num*sign);
                num = 0, sign = -1;
            }
            else if(s[i] == '('){
                st.push(ans);
                st.push(sign);
                num = 0, sign = 1, ans = 0;
            }
            else if(s[i] == ')'){
                ans+=(sign*num);
                int a = st.top(); st.pop();
                num = 0;
                ans*=a;
                int b = st.top(); st.pop();
                ans+=b;
            }
        }
        ans+=(sign*num);
        return ans;
    }
};
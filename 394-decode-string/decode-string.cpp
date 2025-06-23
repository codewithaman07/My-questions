class Solution {
public:
    string decodeString(string s) {
        stack<int>nums;
        stack<string>st;
        int num = 0;
        string curr;
        for(char ch : s){
            if(isdigit(ch)) num = num*10+(ch-'0');
            else if(ch == '['){
                nums.push(num);
                num = 0;
                st.push(curr);
                curr.clear();
            }
            else if(ch == ']'){
                string prev = st.top();
                st.pop();
                int x = nums.top();
                nums.pop();
                string temp;
                for(int i = 0; i<x; i++) temp+=curr;
                curr = prev+temp;
            }
            else curr.push_back(ch);
        }
        return curr;
    }
};
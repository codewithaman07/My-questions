class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int>st;
        int n = temperatures.size();
        vector<int>ans(n,0);
        for(int i = n-1; i>=0; i--){
            while(!st.empty() && temperatures[i]>=temperatures[st.top()]) st.pop();
            if(!st.empty()) ans[i] = abs(i-st.top());
            st.push(i);
        }
        return ans;
    }
};
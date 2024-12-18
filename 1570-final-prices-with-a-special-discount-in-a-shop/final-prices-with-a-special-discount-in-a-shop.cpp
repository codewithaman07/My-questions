class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        stack<int>st;
        vector<int>nse(n,-1);
        for(int i = n-1; i>=0; i--){
            while(!st.empty() && prices[st.top()] > prices[i]) st.pop();
            if(!st.empty()) nse[i] = prices[st.top()];
            st.push(i);
        }
        for(int i = 0; i<n; i++){
            if(nse[i] == -1) nse[i] = prices[i];
            else nse[i] = prices[i]-nse[i];
        }
        return nse;
    }
};

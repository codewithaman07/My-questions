class Solution {
public:
    #define ll long long
    long long bowlSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int>pre(n, -1), next(n,-1);
        stack<int>st;
        for(int i = 0; i<n; i++){
            while(!st.empty() && nums[st.top()] < nums[i]) st.pop();
            if(!st.empty()) pre[i] = st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i = n-1; i>=0; i--){
            while(!st.empty() && nums[st.top()] < nums[i]) st.pop();
            if(!st.empty()) next[i] = st.top();
            st.push(i);
        }
        ll ans = 0;
        for(int i = 0; i<n; i++){
            if(pre[i] != -1 && next[i] != -1) ans++; 
        }
        return ans;
    }
};
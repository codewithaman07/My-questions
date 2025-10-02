class Solution {
public:
    vector<int> asteroidCollision(vector<int>& nums) {
        stack<int>st;
        for(int num : nums){
            if(num > 0) st.push(num);
            else{
                while(!st.empty() && st.top() > 0 && st.top() < -num) st.pop();
                if(st.empty() || st.top() < 0) st.push(num);
                if(!st.empty() && st.top() == -num) st.pop();
            }
        }
        int n = st.size();
        vector<int>ans(n);
        n--;
        while(!st.empty()){
            ans[n--] = st.top();
            st.pop();
        }
        return ans;
    }
};
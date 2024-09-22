class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        stack<int>st;
        int n = arr.size();
        for(int it : arr){
            if(it>0) st.push(it);
            else{
                while(!st.empty() && st.top()< -it && st.top()>0) st.pop();
                if(st.empty() || st.top()<0) st.push(it);
                if(!st.empty() && st.top() == -it) st.pop();
            }
        }
        int i = st.size()-1;
        vector<int>ans(i+1);
        while(!st.empty()){
            ans[i--] = st.top();
            st.pop();
        }
        return ans;
    }
};
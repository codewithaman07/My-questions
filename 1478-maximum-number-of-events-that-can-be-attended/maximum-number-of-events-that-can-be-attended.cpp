class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int l = INT_MAX, r = INT_MIN, n = events.size(), ans = 0, j = 0;
        for(auto e : events){
            l = min(e[0], l);
            r = max(e[1], r);
        }
        sort(events.begin(), events.end());
        multiset<int>st;
        for(int i = l; i<=r; i++){
            while(j<n && events[j][0] <= i){
                st.insert(events[j][1]);
                j++;
            }
            while(!st.empty() && *st.begin() < i) st.erase(st.begin());
            if(!st.empty() && *st.begin() >= i){
                ans++;
                st.erase(st.begin());
            }
        }
        return ans;
    }
};
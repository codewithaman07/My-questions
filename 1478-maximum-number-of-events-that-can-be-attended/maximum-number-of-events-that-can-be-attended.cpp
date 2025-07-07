class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end());
        int l = INT_MAX, r = INT_MIN, ans = 0;
        for(auto e : events){
            l = min(l, e[0]);
            r = max(r,e[1]);
        }
        priority_queue<int,vector<int>, greater<int>>pq;
        int j = 0, n = events.size();
        for(int i = l; i<=r; i++){
            while(j<n && events[j][0] == i){
                pq.push(events[j][1]);
                j++;
            }
            while(!pq.empty() && pq.top()<i) pq.pop();
            if(!pq.empty()){
                ans++;
                pq.pop();
            }
        }
        return ans;
    }
};
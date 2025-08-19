class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        unordered_map<int,unordered_set<int>>mp;
        for(auto &v : points){
            mp[v[0]].insert(v[1]);
        }
        int ans = INT_MAX, n = points.size();
        for(int i = 0; i<n; i++){
            for(int j = i+1; j<n; j++){ 
                int x1 = points[i][0], y1 = points[i][1];
                int x2 = points[j][0], y2 = points[j][1];
                if(x1 != x2 && y1 != y2){
                    if(mp[x1].find(y2) != mp[x1].end() && mp[x2].find(y1) != mp[x2].end()){
                        int x = abs(x1-x2);
                        int y = abs(y1-y2);
                        ans = min(ans, x*y);
                    }
                }
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};
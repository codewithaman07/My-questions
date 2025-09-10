class Solution {
public:
    #define ll long long
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
        map<ll,ll>painting;
        vector<vector<ll>>totalPaintings;
        for(auto &seg : segments){
            int start = seg[0];
            int end = seg[1];
            int col = seg[2];
            painting[start]+=col;
            painting[end]-=col;
        }
        ll sum = 0, prev = -1;
        for(auto &[idx, col] : painting){
            if(sum > 0 && prev != -1){
                totalPaintings.push_back({prev, idx, sum});
            }
            sum+=col;
            prev = idx;
        }
        return totalPaintings;
    }
};
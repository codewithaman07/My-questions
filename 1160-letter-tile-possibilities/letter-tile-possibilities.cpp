class Solution {
public:
    void solve(string &tiles, vector<bool>&used, unordered_set<string>&st, string &curr, int &n){
        st.insert(curr);
        for(int i = 0; i<n; i++){
            if(used[i]) continue;
            used[i] = 1;
            curr+=tiles[i];
            solve(tiles, used, st, curr, n);
            used[i] = 0;
            curr.pop_back();
        }
    }
    int numTilePossibilities(string tiles) {
        int n = tiles.size();
        vector<bool>used(n,0);
        unordered_set<string>st;
        string curr;
        solve(tiles, used, st, curr, n);
        return st.size()-1;
    }
};
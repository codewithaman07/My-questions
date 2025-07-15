class Solution {
public:
    int minDeletions(string s) {
        int n = s.size(), ans = 0;
        unordered_map<int,int>mp;
        unordered_set<int>st;
        for(char ch : s) mp[ch]++;
        for(auto [x,y] : mp){
            while(y>0 && st.count(y)){
                y--;
                ans++;
            }
            st.insert(y);
        }
        return ans;
    }
};
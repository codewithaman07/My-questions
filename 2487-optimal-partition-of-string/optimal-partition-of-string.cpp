class Solution {
public:
    int partitionString(string s) {
        unordered_map<int,int>mp;
        int cnt = 1;
        for(int i = 0; i<s.size(); i++){
            if(mp.count(s[i])){
                cnt++;
                mp.clear();
            }
            mp[s[i]]++;
        }
        return cnt;
    }
};
class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        unordered_map<string,int>mp;
        for(auto i : bannedWords){
            mp[i]++;
        }
        int cnt = 0;
        for(auto i : message){
            if(mp.count(i)) cnt++;
            if(cnt>=2) return 1;
        }
        return 0;
    }
};
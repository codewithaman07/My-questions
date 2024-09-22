class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>>mp;
        for(string &s : strs){
            vector<int>cnt(26,0);
            for(char &ch : s){
                cnt[ch-'a']++;
            }
            string key;
            for(int i = 0; i<26; i++){
                key+= to_string(cnt[i])+"#";
            }
            mp[key].push_back(s);
        }
        vector<vector<string>>ans;
        for(auto &it : mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};
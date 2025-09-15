class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mp;
        for(string s : strs){
            vector<int>freq(26,0);
            for(char ch : s){
                freq[ch-'a']++;
            }
            string key;
            for(int i = 0; i<26; i++){
                key+= to_string(freq[i]);
                key+="#";
            }
            mp[key].push_back(s);
        }
        vector<vector<string>>ans;
        for(auto & [x,y] : mp){
            ans.push_back(y);
        }
        return ans;
    }
};
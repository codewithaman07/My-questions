class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        unordered_map<string,vector<string>>mp;
        for(int i = 0; i<n; i++){
            string s = strs[i];
            vector<int>freq(26,0);
            for(int j = 0; j<s.size(); j++){
                freq[s[j]-'a']++;
            }
            string key;
            for(int j = 0; j<26; j++){
                key+=to_string(freq[j]);
                key+="#";
            }
            mp[key].push_back(s);
        }
        vector<vector<string>>ans;
        for(auto &[x,y] : mp){
            ans.push_back(y);
        }
        return ans;
    }
};
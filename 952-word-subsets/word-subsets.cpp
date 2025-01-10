class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        int n = words1.size(), m = words2.size();
        vector<string>ans;
        vector<int>mp(26,0);
        for(string &s : words2){
            vector<int>mp2(26,0);
            for(char &ch : s) mp2[ch-'a']++;
            for(int i = 0; i<26; i++) mp[i] = max(mp[i], mp2[i]);
        }
        // for(int i = 0; i<26; i++) cout<<mp[i]<<" ";
        // cout<<endl;
        for(string &s : words1){
            vector<int>mp1(26,0);
            for(char &ch : s) mp1[ch-'a']++;
            int f = 1;
            for(int i = 0; i<26; i++){
                if(mp[i] > mp1[i]){
                    f = 0;
                    break;
                }
            }
            if(f) ans.push_back(s);
        }
        return ans;
    }
};
class Solution {
public:
    string rankTeams(vector<string>& votes) {
        int n = votes.size(), m = votes[0].size();
        vector<vector<int>>freq(26, vector<int>(27));
        for(char &c : votes[0]){
            freq[c-'A'][26] = c;
        }
        for(string &vote : votes){
            for(int i = 0; i<m; i++){
                freq[vote[i]-'A'][i]--;
            }
        }
        sort(freq.begin(),freq.end());
        string ans;
        for(int i = 0; i<m; i++) ans+= freq[i][26];
        return ans;
    }
};
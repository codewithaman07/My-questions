class Solution {
public:
    string makeLargestSpecial(string s) {
        int cnt = 0, i = 0, n = s.size();
        vector<string>ans;
        for(int j = 0; j<n; j++){
            if(s[j] == '1') cnt++;
            else cnt--;
            if(!cnt){
                ans.push_back('1'+ makeLargestSpecial(s.substr(i+1, j-i-1)) +'0');
                i = j+1;
            }
        }
        sort(ans.rbegin(), ans.rend());
        string t;
        for(auto v : ans) t+=v;
        return t;
    }
};
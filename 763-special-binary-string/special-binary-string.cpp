class Solution {
public:
    string makeLargestSpecial(string s) {
        int cnt = 0, i = 0;
        vector<string>ans;
        for(int j = 0; j<s.size(); j++){
            if(s[j] == '1') cnt++;
            else cnt--;
            if(cnt == 0){
                ans.push_back('1'+ makeLargestSpecial(s.substr(i+1, j-i-1)) + '0');
                i = j+1;
            }
        }
        sort(ans.begin(),ans.end());
        string t;
        for(int i = ans.size()-1; i>=0; i--){
            t+=ans[i];
        }
        return t;
    }
};
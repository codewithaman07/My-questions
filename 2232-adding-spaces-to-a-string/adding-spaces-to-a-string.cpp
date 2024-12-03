class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int n = s.size(), m = spaces.size(), num = 0;
        // sort(spaces.begin(), spaces.end());
        string ans;
        for(int i = 0; i<n; i++){
            if(num < m && i == spaces[num]){
                ans+=' ';
                num++;
            }
            ans+=s[i];
        }
        return ans;
    }
};
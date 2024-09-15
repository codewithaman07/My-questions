class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        // string t;
        // int ans = 0;
        // for(int i = 0; i<n; i++){
        //     auto x = t.find(s[i]);
        //     if(x != string::npos) t = t.substr(x+1);
        //     t+=s[i];
        //     ans = max(ans, (int)t.size());
        // }
        // return ans;
        int maxi = 0, l = 0, r = n-1;
        map<char,int>mp;
        for(int r = 0; r<n; r++){
            mp[s[r]]++;
            while(mp[s[r]]>1){
                mp[s[l]]--;
                l++;
            }
            maxi = max(maxi, r-l+1);
        }
        return maxi;
    }
};
class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int ans = 0, f = 0;
        unordered_map<string,int>mp;
        for(string &word : words) mp[word]++;
        for(auto &[x,y] : mp){
            string rev = x;
            reverse(rev.begin(), rev.end());
            if(x == rev){
                ans += (y/2)*4;
                if(y%2) f = 1;
                mp[x] = 0;
            }
            else if(mp.count(rev)){
                int num = min(y,mp[rev]);
                ans += num*4;
                mp[x] = 0;
                mp[rev] = 0;
            }
        }
        if(f) ans+=2;
        return ans;
    }
};
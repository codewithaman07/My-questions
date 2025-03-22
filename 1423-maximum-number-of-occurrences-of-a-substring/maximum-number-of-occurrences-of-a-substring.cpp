class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        int n = s.size();
        unordered_map<string,int>mp;
        for(int i = 0; i<=n-minSize; i++){
            string str = s.substr(i,minSize);
            unordered_map<char,int>mp2;
            for(char ch : str) mp2[ch]++;
            if(mp2.size()>maxLetters) continue;
            mp[str]++;
        }
        int ans = 0;
        for(auto &[x,y] : mp) ans = max(ans, y);
        return ans;
    }
};
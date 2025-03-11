class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size(), l = 0, cnt = 0;
        unordered_map<char,int>mp;
        for(int r = 0; r<n; r++){
            char ch = s[r];
            mp[ch]++;
            while(mp.size() == 3){
                char c = s[l];
                cnt+=(n-r);
                cout<<cnt<<" ";
                if(--mp[c] == 0) mp.erase(c);
                l++;
            }
        }
        return cnt;
    }
};
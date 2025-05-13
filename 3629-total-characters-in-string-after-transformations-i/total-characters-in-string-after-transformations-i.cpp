class Solution {
public:
    const int M = 1e9+7;
    int lengthAfterTransformations(string s, int t) {
        int n = s.size();
        vector<int>freq(26,0);
        for(char &ch : s) freq[ch-'a']++;
        for(int i = 0; i<t; i++){
            vector<int>temp(26,0);
            for(int j = 0; j<26; j++){
                if(j == 25){
                    temp[0] = (temp[0]+freq[j])%M;
                    temp[1] = (temp[1]+freq[j])%M;
                }
                else temp[j+1] = (temp[j+1]+freq[j])%M;
            }
            freq = temp;
        }
        int ans = 0;
        for(int i : freq) ans = (ans+i)%M;
        return ans;
    }
};
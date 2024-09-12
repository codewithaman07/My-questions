class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        vector<bool>arr(26,0);
        for(char ch : allowed){
            arr[ch-'a'] = 1;
        }
        int cnt = 0;
        for(int i = 0; i<words.size(); i++){
            int f = 1;
            for(char c : words[i]){
                if(arr[c-'a'] == 0) f = 0;
            }
            cnt+=f;
        }
        return cnt;
    }
};
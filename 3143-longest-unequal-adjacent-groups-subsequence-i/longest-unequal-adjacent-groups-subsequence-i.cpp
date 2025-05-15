class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int a = -1, b = -1, n = groups.size();
        for(int i = n-1; i>=0; i--){
            if(groups[i] == 0) a = i;
            if(groups[i]) b = i;
        }
        vector<string>arr, brr;
        if(a != -1) arr.push_back(words[a]);
        if(b != -1) brr.push_back(words[b]);
        int x = 1;
        if(a != -1){
            for(int i = a+1; i<n; i++){
                if(groups[i] == x){
                    arr.push_back(words[i]);
                    x = !x;
                }
            }
        }
        x = 0;
        if(b != -1){
            for(int i = b+1; i<n; i++){
                if(groups[i] == x){
                    brr.push_back(words[i]);
                    x = !x;
                }
            }
        }
        return arr.size() > brr.size() ? arr : brr;
    }
};
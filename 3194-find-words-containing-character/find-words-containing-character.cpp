class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int>ans;
        int i = 0;
        for(string &word : words){
            sort(word.begin(),word.end());
            auto idx = lower_bound(word.begin(), word.end(), x);
            if(idx != word.end() && *idx == x){
                ans.push_back(i);
            }
            i++;
        }
        return ans;
    }
};
class Solution {
public:
    vector<string>split(string &s){
        stringstream ss(s);
        vector<string>ans;
        string word;
        while(ss >> word){
            ans.push_back(word);
        }
        return ans;
    }
    bool areSentencesSimilar(string sentence1, string sentence2) {
        vector<string>s1 = split(sentence1);
        vector<string>s2 = split(sentence2);
        int n = s1.size(), m = s2.size();
        int i = 0, j = 0;
        int mini = min(n,m);
        while(i<mini && s1[i] == s2[i]) i++;
        while(j+i<mini && s1[n-j-1] == s2[m-j-1]) j++;
        return i+j >=mini;
    }
};
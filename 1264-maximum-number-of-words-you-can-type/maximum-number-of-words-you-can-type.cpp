class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int ans = 0;
        stringstream ss(text);
        string word;
        vector<string>words;
        while(ss >> word){
            words.push_back(word);
        } 
        unordered_set<char>st;
        for(char &ch : brokenLetters) st.insert(ch);
        for(string word : words){
            int f = 1;
            for(char ch : word){
                if(st.count(ch)){
                    f = 0;
                    break;
                }
            }
            if(f) ans++;
        }
        return ans;
    }
};
class Solution {
public:
    string sortVowels(string s) {
        vector<char>temp = {'a','e','i', 'o','u', 'A', 'E', 'I', 'O', 'U'};
        set<char>st(temp.begin(), temp.end());
        vector<int>vowels;
        for(char ch : s){
            if(st.count(ch)) vowels.push_back(ch);
        }
        sort(vowels.begin(), vowels.end());
        int pos = 0;
        for(char &ch : s){
            if(st.count(ch)) ch = vowels[pos++];
        }
        return s;
    }
};
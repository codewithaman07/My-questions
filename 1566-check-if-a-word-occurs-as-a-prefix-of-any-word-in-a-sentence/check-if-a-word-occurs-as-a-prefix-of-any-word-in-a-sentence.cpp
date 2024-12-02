class Solution {
public:
    int isPrefixOfWord(string s, string pat) {
        int n = pat.size(), m = s.size();
        stringstream ss(s);
        string temp;
        int i = 1;
        while(ss >> temp){
            if(temp.find(pat) == 0) return i; 
            i++;
        }
        return -1;
    }
};
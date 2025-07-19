class Solution {
public:
    string processStr(string s) {
        string temp;
        for(char &ch : s){
            if(ch == '*') temp = temp.substr(0, temp.length()-1);
            else if(ch == '#') temp+=temp;
            else if(ch == '%') reverse(temp.begin(), temp.end());
            else temp.push_back(ch);
        }
        return temp;
    }
};
class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string word;
        vector<string>temp;
        while(ss >> word){
            temp.push_back(word);
        }
        s.clear();
        for(int i = temp.size()-1; i>=0; i--){
            s+=temp[i];
            if(i != 0) s+=" ";
        }
        return s;
    }
};
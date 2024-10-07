class Solution {
public:
    int minLength(string s) {
        while(1){
            auto pos1 = s.find("AB");
            if(pos1 != string::npos){
                s.erase(pos1, 2);
            }
            auto pos2 = s.find("CD");
            if(pos2 != string::npos){
                s.erase(pos2, 2);
            }
            if(s.find("AB") == string::npos && s.find("CD") == string::npos) break;
        }
        return s.size();
    }
};
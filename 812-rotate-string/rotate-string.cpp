class Solution {
public:
    bool rotateString(string s, string goal) {
        string temp = s+s;
        if(s.size() != goal.size()) return 0; 
        if(temp.find(goal) != string::npos) return 1;
        return 0;
    }
};
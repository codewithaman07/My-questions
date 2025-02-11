class Solution {
public:
    string solve(string &s,string &t){
        int pos = s.find(t);
        if(pos == string::npos) return s;
        s.erase(pos, t.size());
        return solve(s,t);
    }
    string removeOccurrences(string s, string part) {
        return solve(s,part);
    }
};
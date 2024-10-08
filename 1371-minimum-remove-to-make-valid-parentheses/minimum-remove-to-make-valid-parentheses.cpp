class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.size();
        int open = 0;
        for(int i = 0; i<n; i++){
            if(s[i] == '(') open++;
            else if (s[i] == ')'){
                if(open == 0) s[i] = '#';
                else open--;
            }
        }
        for(int i = n-1; i>=0; i--){
            if(open > 0 && s[i] == '(') s[i] = '#', open--;
        }
        string ans;
        for(char &ch : s){
            if(ch != '#') ans+=ch;
        }
        return ans;
    }
};
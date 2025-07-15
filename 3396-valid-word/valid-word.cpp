class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        int v = 0;
        int c = 0;
        if(n<3) return false;
        for(int i = 0; i<n; i++){
            if(isalpha(s[i])){
                if(s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U'){
                    v++;
                }
                else if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
                    v++;
                }
                else{
                    c++;
                }
            }
            
            if(!isalpha(s[i]) && ! isdigit(s[i])){
                return false;
            }
            
        }
        if(v>=1 && c>=1){
            return true;
        }
        return false;
    }
};
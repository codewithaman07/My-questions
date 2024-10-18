class Solution {
public:
    int maximumValue(vector<string>& strs) {
        int maxi = 0;
        for(string &s : strs){
            int n = s.size();
            int f = 1;
            for(int i = 0; i<n; i++){
                if(isalpha(s[i])){
                    f = 0;
                    break;
                }
            }
            if(f) maxi = max(maxi, stoi(s));
            else maxi = max(maxi, n);
        }
        return maxi;
    }
};
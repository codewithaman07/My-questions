class Solution {
public:
    int possibleStringCount(string word) {
        int ans = 1, n = word.size();
        int i = 0;
        while(i<n){
            int j = i+1;
            while(j<n && word[i] == word[j]) j++;
            int num = j-i;
            if(num>1) ans+=(num-1);
            i = j;
        }
        return ans;
    }
};
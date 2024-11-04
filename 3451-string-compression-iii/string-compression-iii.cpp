class Solution {
public:
    string compressedString(string word) {
        string s = "";
        int i = 0;
        int cnt = 1;
        while(i<word.length()){
            if(word[i] == word[i+1] && i<word.length()-1){
                if(cnt<9){
                    cnt++;
                }
                if(cnt == 9){
                    s+=to_string(cnt);
                    s+=word[i];
                    cnt = 1;
                    i++;
                }
            }
            else{
                s+=to_string(cnt);
                s+=word[i];
                cnt = 1;
            }
            i++;
        }
        return s;
    }
};
class Solution {
public:
    char kthCharacter(int k) {
        string word = "a";
        while(word.size()<k){
            string temp;
            for(int i = 0; i<word.size(); i++){
                temp.push_back((word[i]-'a'+1)%26+'a');
            }
            word = word+temp;
        }
        return word[k-1];
    }
};
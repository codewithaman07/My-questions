class Solution {
public:
    string answerString(string word, int numFriends) {
        int n = word.size();
        if(numFriends == 1) return word;
        char maxi = 'a';
        string ans;
        for(char ch : word) maxi = max(maxi, ch);
        vector<int>arr;
        for(int i = 0; i<n; i++){
            char ch = word[i];
            if(ch == maxi) arr.push_back(i);
        }
        for(int i : arr){
            int len = (i < numFriends) ? (n - numFriends + 1) : (n - i);
            string temp = word.substr(i, len);
            ans = max(ans, temp);
        }
        return ans;
    }
};
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>st(wordList.begin(), wordList.end());
        if(st.find(endWord) == st.end()) return 0;
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        st.erase(beginWord);
        while(!q.empty()){
            string word = q.front().first;
            int cnt = q.front().second;
            q.pop();
            if(word == endWord) return cnt;
            for(int i = 0; i<word.size(); i++){
                char temp = word[i];
                for(char j = 'a'; j<='z'; j++){
                    word[i] = j;
                    if(st.find(word) != st.end()){
                        q.push({word, cnt+1});
                        st.erase(word);
                    }
                }
                word[i] = temp;
            }
        }
        return 0;
    }
};
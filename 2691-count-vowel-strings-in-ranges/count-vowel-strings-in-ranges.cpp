class Solution {
public:
    bool check(string &word){
        int n = word.size();
        bool f1 = 0, f2 = 0;
        if(word[0] == 'a' || word[0]=='e' || word[0]=='i' || word[0]=='o' || word[0]=='u') f1 = 1;
        if(word[n-1] == 'a' || word[n-1]=='e' || word[n-1]=='i' || word[n-1]=='o' || word[n-1]=='u') f2 = 1;
        return f1 and f2;
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int>pre(n,0);
        for(string &word : words){
            if(!check(word)) word = "";
        }
        if(words[0] != "") pre[0] = 1;
        for(int i = 1; i<n; i++){
            if(words[i] != "") pre[i] = pre[i-1]+1;
            else pre[i] = pre[i-1];
        }
        for(int i = 0; i<n; i++) cout<<pre[i]<<" ";
        vector<int>ans;
        n = queries.size();
        for(int i = 0; i<n; i++){
            int l = queries[i][0];
            int r = queries[i][1];
            if(l>0) ans.push_back(pre[r]-pre[l-1]);
            else ans.push_back(pre[r]);
        }
        return ans;
    }
};
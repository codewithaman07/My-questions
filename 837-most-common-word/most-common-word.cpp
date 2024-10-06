class Solution {
public:
    vector<string>split(string &s){
        for(char &ch : s){
            if(ispunct(ch)) ch = ' ';
        }
        vector<string>ans;
        stringstream ss(s);
        string word;
        while(ss >> word){
            ans.push_back(clean(word));
        }
        return ans;
    }
    string clean(string &word){
        string s;
        for(char ch : word){
            if(isalpha(ch)) s+=tolower(ch);
        }
        return s;
    }
    string mostCommonWord(string paragraph, vector<string>& banned) {
        vector<string>s = split(paragraph);
        set<string>st;
        for(string s : banned){
            st.insert(clean(s));
        }
        map<string, int>mp;
        for(string i : s){
            if(!st.count(clean(i))){
                mp[i]++;
            }
        }
        int maxi = -1;
        string res;
        for(auto i : mp){
            if(maxi < i.second){
                res = i.first;
                maxi = i.second;
            }
        }
        return res;
    }
};
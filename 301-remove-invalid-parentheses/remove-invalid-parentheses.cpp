class Solution {
public:
    bool valid(string &s){
        int n = s.size(), num = 0;
        for(int i = 0; i<n; i++){
            if(s[i] == '(') num++;
            else if (s[i] == ')'){
                if(num == 0) return 0;
                else num--;
            }
        }
        return num == 0;
    }
    void solve(string temp, string &s, set<string>&st, int i, int &cnt, int &n){
        if(temp.size() == n-cnt){
            if(valid(temp)) st.insert(temp);
            return;
        }
        if(i>=n) return;
        temp.push_back(s[i]);
        solve(temp,s,st,i+1,cnt,n);
        temp.pop_back();
        solve(temp,s,st,i+1,cnt,n);
    }
    vector<string> removeInvalidParentheses(string s) {
        int num = 0, cnt = 0, n = s.size();
        for(int i = 0; i<n; i++){
            if(s[i] == '(') num++;
            else if (s[i] == ')'){
                if(num == 0) cnt++;
                else num--;
            }
        }
        cnt+=num;
        string temp;
        set<string>st;
        solve(temp,s,st, 0, cnt, n);
        vector<string>ans;
        for(auto it : st){
            ans.push_back(it);
        }
        if(ans.size() == 0) return {""};
        return ans;
    }
};
class Solution {
public:
    vector<int> longestCommonPrefix(vector<string>& words) {
        int n = words.size();
        vector<int> pre, ans(n,0);
        for(int i = 0; i<n-1; i++){
            string s = words[i];
            string t = words[i+1];
            int cnt = 0;
            for(int j = 0; j<min(s.size(), t.size()); j++){
                if(s[j] == t[j]) cnt++;
                else break;
            }
            pre.push_back(cnt);
        }
        vector<int> suf = pre;
        int maxi = 0;
        for(int i = 0; i<pre.size(); i++){
            pre[i] = max(pre[i], maxi);
            maxi = max(maxi,pre[i]);
        }
        maxi = 0;
        for(int i = suf.size()-1; i>0; i--){
            suf[i] = max(suf[i],maxi);
            maxi = max(suf[i],maxi);
        }
        for(int i = 0; i<n; i++){
            int suffix = 0, prefix = 0;
            if(i>=2) prefix = pre[i-2];
            if(i<n-2) suffix = suf[i+1];
            string s,t;
            if(i>0) s = words[i-1];
            if(i<n-1) t = words[i+1];
            int cnt = 0, x = s.size(), y = t.size();
            for(int j = 0; j<min(x,y); j++){
                if(s[j] == t[j]) cnt++;
                else break;
            }
            ans[i] = max({prefix, suffix, cnt});
            // cout<<"pre : suf :"<<prefix<<" "<<suffix<<endl;
        }
        return ans;
    }
};

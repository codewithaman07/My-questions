class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int>mp;
        for(char &ch : s) mp[ch]++;
        priority_queue<pair<int,char>>pq;
        for(auto &[x,y] : mp){
            pq.push({y,x});
        }
        string ans;
        while(pq.size()>=2){
            auto [num, ch] = pq.top();
            pq.pop();
            auto [num2, ch2] = pq.top();
            pq.pop();
            ans+=ch;
            ans+=ch2;
            if(num-1>0) pq.push({num-1,ch});
            if(num2-1>0) pq.push({num2-1,ch2});
        }
        if (!pq.empty()){
            auto [num, ch] = pq.top();
            if(num > 1) return "";
            ans += ch;
        }
        int n = ans.size();
        for(int i = 0; i<n-1; i++){
            if(ans[i] == ans[i+1]) return "";
        }
        return ans;
    }
};
class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        unordered_map<char,int>mp;
        priority_queue<char>pq;
        string ans;
        for(char &ch : s) mp[ch]++;
        for(auto &it : mp) pq.push(it.first);
        while(!pq.empty()){
            char ch = pq.top();
            pq.pop();
            int temp = min(mp[ch], repeatLimit);
            ans.append(temp,ch);
            mp[ch]-=temp;
            if(mp[ch] > 0 && !pq.empty()){
                char a = pq.top();
                pq.pop();
                ans+=a;
                mp[a]--;
                if(mp[a] > 0) pq.push(a);
                pq.push(ch);
            }
        }
        return ans;
    }
};
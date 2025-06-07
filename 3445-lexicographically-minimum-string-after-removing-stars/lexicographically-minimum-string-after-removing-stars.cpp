class Solution {
public:
    string clearStars(string s) {
        string ans;
        int n = s.size();
        priority_queue<pair<char,int>, vector<pair<char,int>>, greater<pair<char,int>>>pq;
        for(int i = 0; i<n; i++){
            if(s[i] != '*') pq.push({s[i], -i});
            else pq.pop();
        }
        vector<pair<int,int>>temp;
        while(!pq.empty()){
            auto [x,y] = pq.top();
            pq.pop();
            temp.push_back({abs(y),x});
        }
        sort(temp.begin(),temp.end());
        for(auto [x,y] : temp) ans.push_back(y);
        return ans;
    }
};
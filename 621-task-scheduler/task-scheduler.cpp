class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int>mp;
        int cycle = n+1, ans = 0;
        for(int i = 0; i<tasks.size(); i++){
            mp[tasks[i]]++;
        }
        priority_queue<int>pq;
        for(auto &[x, y] : mp){
            pq.push(y);
        }
        while(!pq.empty()){
            vector<int>temp;
            for(int i = 0; i<cycle; i++){
                if(!pq.empty()){
                    temp.push_back(pq.top()-1);
                    pq.pop();
                }
            }
            for(int num : temp){
                if(num > 0) pq.push(num);
            }
            ans += pq.empty() ? temp.size() : cycle;
        }
        return ans;
    }
};
class Solution {
public:
    #define ll long long
    long long pickGifts(vector<int>& gifts, int k) {
        ll ans = 0;
        priority_queue<ll>pq;
        for(int &num : gifts) pq.push(num);
        while(k-- && !pq.empty()){
            ll num = pq.top();
            pq.pop();
            pq.push((int)sqrt(num));
        }
        while(!pq.empty()){
            ll num = pq.top();
            pq.pop();
            ans+=num;
        }
        return ans;
    }
};
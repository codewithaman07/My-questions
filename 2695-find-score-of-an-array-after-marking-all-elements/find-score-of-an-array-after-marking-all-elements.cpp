class Solution {
public:
    #define ll long long
    long long findScore(vector<int>& nums) {
        ll ans = 0;
        int n = nums.size();
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        for(int i = 0; i<n; i++){
            pq.push({nums[i], i});
        }
        while(!pq.empty()){
            auto temp = pq.top();
            pq.pop();
            int num = temp.first;
            int idx = temp.second;
            if(nums[idx] != -1){
                ans+=num;
                nums[idx] = -1;
                if(idx > 0) nums[idx-1] = -1;
                if(idx < n-1) nums[idx+1] = -1;
            }
        }
        return ans;
    }
};
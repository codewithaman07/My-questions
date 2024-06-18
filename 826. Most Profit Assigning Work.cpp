class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = profit.size(), m = worker.size();
        vector<pair<int,int>>arr(n);
        for(int i = 0; i<n; i++){
            arr[i] = make_pair(difficulty[i],profit[i]);
        }
        sort(worker.begin(),worker.end());
        sort(arr.begin(),arr.end());
        int idx = 0, ans = 0, maxi = 0;
        for(int i = 0; i<m; i++){
            while(idx<n && worker[i]>=arr[idx].first){
                ans = max(ans,arr[idx].second);
                idx++;
            }
            maxi+=ans;
        }
        return maxi;
    }
};

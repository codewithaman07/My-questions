class Solution {
public:
    #define ll long long
    long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {
        ll ans = 0;
        int n = grid.size(), m = grid[0].size();
        priority_queue<int>pq;
        for(int i = 0; i<n; i++){
            sort(grid[i].begin(), grid[i].end(), greater<int>());
        }
        for(int i = 0; i<n; i++){
            for(int j = 0; j<limits[i]; j++){
                pq.push(grid[i][j]);
            }
        }
        while(!pq.empty() && k--){
            ans+=pq.top();
            pq.pop();
        }
        return ans;
    }
};
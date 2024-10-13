class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n = nums.size(), maxi = INT_MIN;
        vector<int>range = {0,INT_MAX};
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>pq;
        for(int i = 0; i<n; i++){
            pq.push({nums[i][0], i, 0});
            maxi = max(maxi, nums[i][0]);
        } 
        while(!pq.empty()){
            vector<int>curr = pq.top();
            pq.pop();
            int mini = curr[0], list = curr[1], idx = curr[2];
            if(maxi-mini < range[1]-range[0]){
                range[0] = mini;
                range[1] = maxi;
            }
            if(idx+1 < nums[list].size()){
                pq.push({nums[list][idx+1], list, idx+1});
                maxi = max(maxi, nums[list][idx+1]);
            }
            else break;
        }
        return range;
    }
};
// class Solution {
// public:
//     vector<int> smallestRange(vector<vector<int>>& nums) {
//         int n = nums.size();
//         vector<int>arr(n,0);
//         vector<int>range = {0,INT_MAX};
//         while(1){
//             int mini = INT_MAX, maxi = INT_MIN, idx = 0;
//             for(int i = 0; i<n; i++){
//                 int temp = nums[i][arr[i]];
//                 if(temp < mini){
//                     mini = temp;
//                     idx = i;
//                 }
//                 if(temp > maxi) maxi = temp;
//             }
//             if(maxi-mini < range[1]-range[0]){
//                 range[0] = mini;
//                 range[1] = maxi;
//             }
//             arr[idx]++;
//             if(arr[idx] == nums[idx].size()) break;
//         }
//         return range;
//     }
// };
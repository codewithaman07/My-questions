class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n = nums.size();
        vector<int>arr(n,0);
        vector<int>range = {0,INT_MAX};
        while(1){
            int mini = INT_MAX, maxi = INT_MIN, idx = 0;
            for(int i = 0; i<n; i++){
                int temp = nums[i][arr[i]];
                if(temp < mini){
                    mini = temp;
                    idx = i;
                }
                if(temp > maxi) maxi = temp;
            }
            if(maxi-mini < range[1]-range[0]){
                range[0] = mini;
                range[1] = maxi;
            }
            arr[idx]++;
            if(arr[idx] == nums[idx].size()) break;
        }
        return range;
    }
};
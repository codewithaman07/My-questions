class Solution {
public:
    int fun(vector<int>&nums, int x, int val){
        int n = nums.size(), cnt = 0;
        for(int i = 0; i<n; i++){
            int num = abs(val-nums[i]);
            if(num%x) return -1;
            cnt+=(num/x);
        }
        return cnt;
    }
    int minOperations(vector<vector<int>>& grid, int x) {
        int n = grid.size(), m = grid[0].size();
        vector<int>nums;
        for(int i = 0; i<n; i++) for(int j = 0; j<m; j++) nums.push_back(grid[i][j]);
        sort(nums.begin(),nums.end());
        n = nums.size();
        if(n == 1) return fun(nums,x,nums[0]);
        if(n%2) return min(fun(nums,x,nums[n/2-1]), fun(nums,x,nums[n/2]));
        else return fun(nums,x,nums[n/2]);
    }
};
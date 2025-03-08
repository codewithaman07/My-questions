class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), sum = 0;
        vector<int>diff(n,0);
        for(auto it : queries){
            diff[it[0]]++;
            if(it[1]+1<n) diff[it[1]+1]--;
        }
        for(int i = 0; i<n; i++){
            sum+=diff[i];
            if(sum<nums[i]) return 0;
        }
        return 1;
    }
};
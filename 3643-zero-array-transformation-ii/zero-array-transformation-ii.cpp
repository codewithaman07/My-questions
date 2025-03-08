class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries, int k) {
        int n = nums.size(), sum = 0;
        vector<int>diff(n,0);
        int cnt = 0;
        for(auto it : queries){
            if(cnt>=k) break;
            cnt++;
            diff[it[0]]+= it[2];
            if(it[1]+1<n) diff[it[1]+1]-= it[2];
        }
        for(int i = 0; i<n; i++){
            sum+=diff[i];
            if(sum<nums[i]) return 0;
        }
        return 1;
    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), q = queries.size();
        if(!isZeroArray(nums,queries,q)) return -1;
        int l = 0, r = q, ans = q;
        while(l<=r){
            int m = l+(r-l)/2;
            if(isZeroArray(nums, queries,m)){
                ans = m;
                r = m-1;
            }
            else l = m+1;
        }
        return ans;
    }
};
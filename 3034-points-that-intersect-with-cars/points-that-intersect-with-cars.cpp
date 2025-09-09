class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        int maxi = 0;
        for(auto num : nums){
            maxi = max(maxi, num[1]);
        }
        vector<int>diff(maxi+2,0);
        for(auto num : nums){
            diff[num[0]]++;
            diff[num[1]+1]--;
        }
        for(int i = 1; i<diff.size(); i++){
            diff[i] = diff[i-1]+diff[i];
        }
        int ans = 0;
        for(int num : diff){
            if(num>0) ans++;
        }
        return ans;
    }
};
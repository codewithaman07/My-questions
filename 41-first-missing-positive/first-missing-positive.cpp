class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        vector<int>seen(n+1, 0);
        for(int num : nums){
            if(num>0 && num<=n) seen[num] = 1;
        }
        for(int i = 1; i<=n; i++){
            if(!seen[i]) return i;
        }
        return n+1;
    }
};
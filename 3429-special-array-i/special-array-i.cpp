class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 1;
        if(n == 2){
            if((nums[0]&1) == (nums[1]&1)) return 0;
            else return 1;
        }
        for(int i = 1; i<n-1; i++){
            int a = nums[i-1]&1;
            int b = (nums[i]&1);
            int c = (nums[i+1]&1);
            if(a == b || b == c) return 0;
        }
        return 1;
    }
};
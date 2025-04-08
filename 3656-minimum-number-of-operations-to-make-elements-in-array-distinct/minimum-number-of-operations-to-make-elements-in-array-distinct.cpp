class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_set<int>st;
        int n = nums.size(), idx = -1;
        for(int i = n-1; i>=0; i--){
            if(st.count(nums[i])){
                idx = i+1;
                break;
            }
            st.insert(nums[i]);
        }
        if(idx == -1) return 0;
        int ans = (idx+2)/3; // a/b = a+b-1/b;
        return ans;
    }
};
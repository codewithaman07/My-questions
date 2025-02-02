class Solution {
public:
    bool check(vector<int>& nums) {
        int size = nums.size(), cnt = 0;
        for(int idx = 0; idx < size; idx++){
            if(nums[idx] > nums[(idx+1)%size]) cnt++;
        }
        return cnt <= 1 ? true : false;
    }
};
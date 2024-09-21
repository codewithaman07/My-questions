class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int size = nums.size();
        deque<int>dq;
        vector<int>ans;
        for(int idx = 0; idx < size; idx++){
            if(!dq.empty() && idx-dq.front() >= k){
                dq.pop_front();
            }
            while(!dq.empty() && nums[dq.back()] <= nums[idx]){
                dq.pop_back();
            }
            dq.push_back(idx);
            if(idx >= k-1){
                ans.push_back(nums[dq.front()]);
            }
        }
        return ans;
    }
};
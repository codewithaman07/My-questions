class Solution {
public:
    bool fun(vector<int>&nums, int maxOperations, int mid, int n){
        int cnt = 0;
        for(int i = 0; i<n; i++){ // ceil (a+b-1)/b
            cnt+= ((nums[i]+mid-1)/mid)-1; // one bag was already their 
        }
        return cnt <= maxOperations;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int l = 1, h = *max_element(nums.begin(), nums.end()), n = nums.size();
        while(l<=h){
            int mid = l+(h-l)/2;
            if(fun(nums, maxOperations, mid, n)) h = mid-1;
            else l = mid+1;
        }
        return l;
    }
};
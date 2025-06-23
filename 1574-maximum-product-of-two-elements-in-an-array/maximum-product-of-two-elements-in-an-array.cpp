class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mini = INT_MAX, maxi = INT_MIN, x = 0, y = 0, n = nums.size();
        for(int i = 0; i<n; i++){
            if(nums[i]>maxi){
                maxi = nums[i];
                x = i;
            }
            if(nums[i]<mini){
                mini = nums[i];
                y = i;
            }
        }
        mini--;
        maxi--;
        int ans = 0;
        for(int i = 0; i<n; i++){
            if(i != x) ans = max(ans, maxi*(nums[i]-1));
            if(i != y) ans = max(ans, mini*(nums[i]-1));
        }
        return ans;
    }
};
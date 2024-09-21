class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProd = INT_MIN;
        int size = nums.size();
        int prod = 1;
        for(int idx = 0; idx < size; idx++){
            prod = prod*nums[idx];
            maxProd = max(maxProd, prod);
            if(prod == 0){
                prod = 1;
            }
        }
        prod = 1;
        for(int idx = size-1; idx>=0; idx--){
            prod = prod*nums[idx];
            maxProd = max(maxProd, prod);
            if(prod == 0){
                prod = 1;
            }
        }
        return maxProd;
    }
};

// class Solution {
// public:
//     int maxProduct(vector<int>& nums) {
//         int n = nums.size();
//         int maxi = nums[0];
//         int mini = nums[0];
//         int result = nums[0];
//         for(int i = 1; i<n; i++){
//             if(nums[i]<0){
//                 swap(maxi, mini);
//             }
//             maxi = max(nums[i],nums[i]*maxi);
//             mini = min(nums[i],nums[i]*mini);
//             result = max(result, maxi);
//         }
//         return result;
//     }
// };
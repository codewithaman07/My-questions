class Solution {
public:
    int minSubArraySum(vector<int>& nums) {
        int minSum = INT_MAX, currSum = 0;
        for (int num : nums) {
            currSum += num;
            minSum = min(minSum, currSum);
            if (currSum > 0) currSum = 0;
        }
        return minSum;
    }
    int maxSubArraySum(vector<int>& nums) {
        int maxSum = INT_MIN, minSum = 0, currSum = 0;
        for (int num : nums) {
            currSum += num;
            maxSum = max(maxSum, currSum - minSum);
            minSum = min(minSum, currSum);
        }
        return maxSum;
    }
    int maxAbsoluteSum(vector<int>& nums) {
        int a = maxSubArraySum(nums);
        a = abs(a);
        int b = minSubArraySum(nums);
        b = abs(b);
        return max(a,b);
    }
};
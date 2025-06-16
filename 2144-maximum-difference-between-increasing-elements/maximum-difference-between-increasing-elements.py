class Solution:
    def maximumDifference(self, nums: List[int]) -> int:
        n = len(nums)
        ans = -1
        mini = inf
        for i in range(n):
            mini = min(mini, nums[i])
            if(nums[i]>mini):
                ans = max(ans, nums[i]-mini)
        
        return ans
        
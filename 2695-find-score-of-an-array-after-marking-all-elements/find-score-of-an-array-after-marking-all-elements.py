class Solution:
    def findScore(self, nums: List[int]) -> int:
        ans = 0
        n = len(nums)
        pq = [(num, i) for i, num in enumerate(nums)]
        heapq.heapify(pq)

        while pq:
            num, i = heapq.heappop(pq)
            if nums[i] != -1:
                ans+=num
                nums[i] = -1
                if(i > 0):
                    nums[i-1] = -1
                if(i < n-1):
                    nums[i+1] = -1
        
        return ans

        
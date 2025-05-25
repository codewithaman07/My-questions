class Solution(object):
    def fun(self, n):
        if n<2:
            return False
        if n == 2:
            return True
        if n%2 == 0:
            return False
        i = 3
        while i*i<=n:
            if n%i == 0:
                return False
            i+=2
        return True

    def sumOfLargestPrimes(self, s):
        n = len(s)
        nums = set()
        for i in range(n):
            for j in range(i,n):
                temp = s[i:j+1]
                num = int(temp)
                if self.fun(num):
                    nums.add(num)
        nums = sorted(nums, reverse = True)
        return sum(nums[0:3])
        """
        :type s: str
        :rtype: int
        """
        
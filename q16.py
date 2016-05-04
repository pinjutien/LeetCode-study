# Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.
class Solution(object):
    def threeSumClosest(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        nums.sort()
        if (len(nums) <= 3):
            return sum(nums)
            
        min_diff = 2**32
        res = 0
        for i in xrange(len(nums)-2):
            L, R = i +1, len(nums) -1
            while (L < len(nums) -1) and (R > i) and (L < R) :
                
                sum3 = nums[L] + nums[R] + nums[i]
                diff = abs(sum3 - target)
                if diff == 0:
                    return sum3
                
                if diff <= min_diff:
                    min_diff = diff
                    res = sum3
    
                if sum3 <= target:
                    L += 1
                else:
                    R -= 1
                
        return res 
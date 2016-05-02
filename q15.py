# Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
# 
# Note:
# Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
# The solution set must not contain duplicate triplets.
class Solution(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """

        if len(nums) == 0:
            return []
        if (len(nums) == 1) and (nums[0] == 0):
            return []

        nums.sort()
        if (nums[0] > 0):
            return []

        tmp = []
        # first element is negative.
        for i in xrange(len(nums)-2):
            L, R = i +1, len(nums) -1
            while (L < len(nums) -1) and (R > i) and (L < R) :
                if nums[L] + nums[R] == -nums[i]:
                    tmp.append([nums[i], nums[L], nums[R]])
                    L += 1
                    R -= 1
                    while (nums[L] == nums[L-1]) and (L< R):
                        L += 1
                    while (nums[R] == nums[R+1]) and (L< R):
                        R -= 1
                elif nums[L] + nums[R] < -nums[i]:
                    L += 1
                else:
                    R -= 1
        res = []
        for x in xrange(len(tmp)):
            if not tmp[x] in res:
                res.append(tmp[x])
                
        return res  
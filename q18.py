# Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + # c + d = target? Find all unique quadruplets in the array which gives the sum of target.
class Solution(object):
    def threeSumTarget(self, nums, target):
        nums.sort()
        if (len(nums) <= 3):
            return sum(nums)
        for i in xrange(len(nums)-2):
            L, R = i +1, len(nums) -1
            while (L < len(nums) -1) and (R > i) and (L < R) :
                
                sum3 = nums[L] + nums[R] + nums[i]
                diff = abs(sum3 - target)
                if diff == 0:
                    return [nums[i], nums[L], nums[R]]
                    
                if sum3 <= target:
                    L += 1
                else:
                    R -= 1
                
        return []  
 
    def fourSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        
        if len(nums) == 0:
            return []
        if (len(nums) <= 4):
            if (sum(nums) == target):
                return sum(nums)
            else: return []    

        nums.sort()
        if (nums[0] > target) and (nums[0] > 0):
            return []
        print nums, len(nums)
        res = []
        for i in xrange(len(nums) - 3):
            print i
            tmp = []
            tmp = self.threeSumTarget(nums[i:], target - nums[i])
            print tmp
            if len(tmp) != 0:
                tmp.append(nums[i])
                tmp.sort()
                res.append(tmp)

        return res
# reference: http://chaoren.is-programmer.com/posts/45308.html
class Solution(object):
    def fourSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        
        if len(nums) < 4: return []  

        nums.sort()
        lens_nums, dictx = len(nums), {}
        for i in xrange(lens_nums-1):
            for j in xrange(i+1, lens_nums):
                if nums[i] + nums[j] in dictx:
                    dictx[nums[i] + nums[j]].append((i,j))
                else:
                    dictx[nums[i] + nums[j]] = [(i, j)]

        result = set()
        for i in xrange(lens_nums-1):
            for j in xrange(i+1, lens_nums):
                temp = target - nums[i] - nums[j]
                if temp in dictx: # if we use "if temp in dictx.keys()" the Time limit exceeded.
                    for k in dictx[temp]:
                        if k[0] > j:
                            result.add(( nums[i], nums[j], nums[k[0]], nums[k[1]] ))
        final = [ list(i) for i in result ]
        return final
from time import time

def twoSum(nums, target):
    """
    :type nums: List[int]
    :type target: int
    :rtype: List[int]
    """
    for i in xrange(len(nums)-1):
        for j in xrange(i+1, len(nums)):
            if (nums[i] + nums[j] == target):
                return [i, j]
        
    return 'no index are found!'
    

## hash table
def twoSum_2(nums, target):
    """
    :type nums: List[int]
    :type target: int
    :rtype: List[int]
    """
    hashmap = {}
    
    for i in xrange(len(nums)):
        hashmap[nums[i]] = i

    for i in xrange(len(nums)):
		comp = target - nums[i]
		if (comp in hashmap.keys()):
			return [i, hashmap[comp]]	
        
    return 'no index are found!'

def twoSum_3(nums, target):
    """
    :type nums: List[int]
    :type target: int
    :rtype: List[int]
    """
    hashmap = {}
    
    for i in xrange(len(nums)):
		comp = target - nums[i]
		if (comp in hashmap.keys()):
			return [i, hashmap[comp]]
		hashmap[nums[i]] = i
      
    return 'no index are found!'
    
if __name__ == '__main__':
	arr = [2, 7, 11, 15]
	target = 9
	s1 = time()
	ans = twoSum(arr, target)
	s2 = time()
	print ans, 'time consumption: ', s2 - s1
	
	s1 = time()
	ans = twoSum_2(arr, target)
	s2 = time()	
	print ans, 'time consumption: ', s2 - s1	

	s1 = time()
	ans = twoSum_3(arr, target)
	s2 = time()	
	print ans, 'time consumption: ', s2 - s1	
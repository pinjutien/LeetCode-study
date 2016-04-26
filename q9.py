class Solution(object):
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        x = str(x)
        x = x.strip(" ")
        
        if len(x) == 0:
            return True
        
        arr = []
        arr_rev = []
        for i in xrange(len(x)):
            arr.append(x[i])
            arr_rev.append(x[len(x) - i -1])
        
        return (arr == arr_rev)
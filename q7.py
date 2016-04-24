class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        pre = ''
        if x < 0:
            pre = '-'
            x = -x
            
        stringx = str(x)
        y = ''
        for i in stringx:
            y = ''.join((i,y))
        
                
        if len(pre) == 0:
            res =  int(y)
        else:
            res = (-1)* int(y)
        
        # deal with overflaw problem: int32 can not be larger than 2**31
        if abs(res) > (2**31):
            return 0
        else:
            return res
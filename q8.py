class Solution(object):
    def myAtoi(self, strx):
        """
        :type str: str
        :rtype: int
        """
        if len(strx) == 0: return 0
        
        strx = strx.strip()
        arr = []
        
        for i in xrange(len(strx)):
            if (i == 0 and strx[i] in ('+', '-')) or (strx[i] >= '0' and strx[i] <= '9'):
                arr.append(strx[i])
            else:
                break
            
        if (arr in ([],['+'], ['-'])):
            return 0
        else:
            num = ''.join(arr)
            if (int(num) >= 2**31):
                return 2**31 -1
            elif (int(num) <= -2**31):
                return -2**31
            else:
                return int(num)
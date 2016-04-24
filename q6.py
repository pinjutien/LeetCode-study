class Solution(object):
    def convert(self, s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """
        if (numRows==1) or (len(s) == 0): return s    
        total_s = ['' for x in xrange(len(s))]
        row, step = -1, 1
        for i in xrange(len(s)):
            row += step
            if row == numRows:
                row -= 2
                step = -1
            elif row == -1:
                row = 1
                step = 1
                
            total_s[row] += s[i]
        res = ''.join(total_s)
        return res  
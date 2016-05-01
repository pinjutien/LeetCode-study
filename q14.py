# Write a function to find the longest common prefix
# string amongst an array of strings.
class Solution(object):
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        
        min_len, ans = 2**32, 0
        min_index = 0
        if len(strs) == 0:
            return ""
        
        for i in xrange(len(strs)):
            if len(strs[i]) < min_len:
                min_len = len(strs[i])
                min_index = i
     
        if min_len == 0:
            return ""
        else:
            xstr = strs[min_index]

            i = 1
            while (i <= min_len):
                tmp_arr = [xstr[:i] in s[:i] for s in strs]

                if (sum(tmp_arr) == len(strs)) and (i >= ans):
                    ans = i
                i += 1

            return xstr[:ans]
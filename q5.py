# 5. Longest Palindromic Substring   
# Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
# reference: solution of leetcode


def centerfunction(s, left, right):
	i, j = left, right
	while (i >= 0) and (j < len(s)) and (s[i] == s[j]):
		i -= 1
		j += 1
	return j - i -1
	
       
class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        a, b = 0, 0
		for i in xrange(len(s)):
			# the len of aplindromes is odd number
			len1 = centerfunction(s,i,i)
			# the len of aplindromes is even number
			len2 = centerfunction(s,i,i+1)
			len_max = max(len2, len1)
			if (len_max > (b-a)):
				a = i - (len_max -1)/2
				b = i + len_max/2	
        return s[a: b+1]
         
if __name__ == '__main__':
	s = "xabba"
	sol = Solution()
	print sol.longestPalindrome(s)        
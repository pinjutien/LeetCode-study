class Solution(object):
    def wordBreak(self, s, wordDict):
        """
        :type s: str
        :type wordDict: List[str]
        :rtype: bool
        """
        
        '''
        dp[i]: 
        true if s[0:i] can be break ie 0-th - (i-1)th char
        
        there are two conditions that make dp[i] is true:
        1. exist k within [0, i], such that s[i-k:i] is in dict (k: length of word in dict)
        2. dp[i-k] = true
        
        ref:
        https://discuss.leetcode.com/topic/8109/simple-dp-solution-in-python-with-description/8
        http://bangbingsyb.blogspot.com/2014/11/leetcode-word-break-i-ii.html
        '''

        len_s = len(s)
        dp = [False] * (len_s + 1)
        dp[0] = True
        for i in range(1, len_s+1):
            for word in wordDict:
                k = len(word)
                if (dp[i-k] and s[i-k:i] == word):
                    dp[i] = True
                    
        return dp[-1]

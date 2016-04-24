# Given a string, find the length of the longest substring without repeating characters.
# 
# Examples:
# 
# Given "abcabcbb", the answer is "abc", which the length is 3.
# 
# Given "bbbbb", the answer is "b", with the length of 1.
# 
# Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

def solution(s):
	lens = len(s)
	i, j = 0, 0
	current_max = 0
	hashset = []
	print s[0]
	print 'lens: ', lens
	while (i < lens & j < lens):
		print (not s[j] in hashset)
		if not s[j] in hashset :
			print 'sj',s[j]
			hashset.append(s[j])
			j += 1
			print j
			current_max = max(j-i, current_max)
		else:
			# hashset.remove(s[i])
			i += 1
			hashset = hashset[i:j]
	return current_max
	
s = 'abcabcbb'
print solution(s)
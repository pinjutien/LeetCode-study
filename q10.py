class Solution(object):
    def isMatch(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: bool
        """
        arr_s = []
        arr_p = []
        # no "*" or "." in string inputs:
        if (not "*" in s) and (not "." in s) and (not "*" in p) and (not "." in p):
            if s == p :
                return True
            else:
                return False
        elif (s[0] == "*") or (p[0] == "*"):
            return False
        else:
            if ( ".*" in s ) or (".*" in p):
                return True
            else:
                i = 0
                while i < len(s) :
                    arr_s.append(s[i])
                    if (i+1 < len(s)) and (s[i+1] == "*"):
                        arr_s.append(s[i])
                        i += 2
                    else:
                        i += 1
                        
                j = 0
                while j < len(p) :
                    arr_p.append(p[j])
                    if (j+1 < len(p)) and (p[j+1] == "*"):
                        arr_p.append(p[j])
                        j += 2                   
                    else:
                        j += 1
                    
                if (set(arr_s) > set(arr_p)) or (set(arr_s) < set(arr_p)) :
                    return True
                else:
                    return False
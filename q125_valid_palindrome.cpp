/*

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

 */


class Solution {
public:
    bool isPalindrome(string s) {
        string res = "";
        for (int i = 0; i < s.size(); i++) {
            if ((isalpha(s[i])) || (isdigit(s[i]))) {
                res += tolower(s[i]);
            }
        }
        
        int left = 0;
        int right = res.size()-1;
        
        if (res.size() == 0 || res.size() ==1) return true;
        
        while(left <= right) {
            
            if(res[left] != res[right]) {
                return false;
            }
            left += 1;
            right -= 1;
        }
        
        return true;
        
    }
};

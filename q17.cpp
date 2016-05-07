class Solution {
public:
    vector<string> res;
    map<char,string>dict;
    // i : the length of any combination. Once its length = the legth of digits,
    // it is one of combination (ie "ad") and we store it in the res vector.
    void functionRe(string digits, int i, string tmp) {
        if (i == digits.length()) {
            res.push_back(tmp);
            return;
        }
        string numbers = dict[digits[i]];
        for (int j = 0; j < numbers.length(); j++) {
            functionRe(digits, i+1, tmp+numbers[j]);
        }

    }
    
    vector<string> letterCombinations(string digits) {
        dict['2']="abc";
        dict['3']="def";
        dict['4']="ghi";
        dict['5']="jkl";
        dict['6']="mno";
        dict['7']="pqrs";
        dict['8']="tuv";
        dict['9']="wxyz";
        if (digits.length() == 0) {return res;}
        
        for (int i = 0 ; i < digits.length(); i++) {
            if ((digits[i] == '1') || (digits[i] == '0') || (digits[i] == '*') || (digits[i] == '#')) {return res;
            }
        }
        // start from the beginning for recursion.
        functionRe(digits, 0, "");
        return res;
    }
};
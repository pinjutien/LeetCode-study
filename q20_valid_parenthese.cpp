class Solution {
public:

    bool is_left_parenthese(char x) {
        if ((x == '(') || (x == '[') || (x == '{')) {
            return true;
        }
        return false;
    }

    bool is_close(char x, char y) {
        if (x == ')') return (y == '(');
        if (x == ']') return (y == '[');
        if (x == '}') return (y == '{');
        return false;
        
    }


    bool isValid(string s) {
        vector<char> char_vector;
        
        if ((s.size() == 1) || (s.size() == 0)) return false;
        
        for (int i = 0; i < s.size(); i++) {
            if (is_left_parenthese(s[i])) {
                char_vector.push_back(s[i]);
            }
            else {
                if ((char_vector.size() == 0) || !(is_close(s[i], char_vector.back()))) {
                    return false;
                }
                char_vector.pop_back();
            }
        
        }
        
        return (char_vector.size()==0);
        
    }
};

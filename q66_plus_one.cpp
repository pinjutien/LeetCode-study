/*

test 1
input:
[1, 2, 9]

output:
[1, 3, 0]


test 2
input:
[9]

output:
[1, 0]

 */


class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> res;
        int num = digits.size();
        int carry = 1;
        
        for (int i = num-1; i >=0; i--) {
            int element = digits[i] + carry;
            if (element >= 10) {
                carry = element/10;
                element = element%10;
            }
            else {
                carry = 0;
            }
            res.push_back(element);
        }
        
        if (carry == 1) {
            res.push_back(carry);
        }
        
        
        reverse(res.begin(), res.end());
        return res;
        
    }
};

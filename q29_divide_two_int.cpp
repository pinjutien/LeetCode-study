class Solution {
public:
	
    // abs() function for INT_MAX, INT_MIN
    unsigned int absu(int value) {
        return (value < 0) ? -((unsigned int)value) : (unsigned int)value;
    }
	
	
    unsigned divide(int dividend_input, int divisor_input) {
        unsigned result = 0;
        int power = 32;
        int prefix = 1;
        
        // handle INT_MIN and INT_MAX operation
        if (dividend_input * divisor_input < 0) prefix = -1;
        if (((dividend_input == INT_MIN) & (divisor_input > 0)) | ((dividend_input == INT_MAX) & (divisor_input < 0))) {
            prefix = -1;
        }
        
        if (((dividend_input == INT_MIN) & (divisor_input < 0)) | ((dividend_input == INT_MAX) & (divisor_input > 0))) {
            prefix = 1;
        }
        
		
        unsigned dividend = absu(dividend_input);
        unsigned divisor = absu(divisor_input);
		
        unsigned long long y_power = static_cast<unsigned long long>(divisor) << power;
        while (dividend >= divisor) {
            while (y_power > dividend) {
                y_power >>= 1;
                power -= 1;
            }
            result += (1U << power);
            dividend -= y_power;
        }
        
        return result* prefix;
    }
};
class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1.empty() || num2.empty()) return "";
        
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        
        // string product_str(num1.size()+num2.size(), '0');
        string product_str(num1.size()+num2.size(),'0');
        int carry_temp, temp;
        
        for (int j = 0; j < num2.size(); j++) {
            int carry_temp = 0;
            temp = num2[j] - '0';
            for (int i = 0; i < num1.size(); i++) {
                // calculate product element by element, and then carry it over to the next product.
                carry_temp += ((num1[i] - '0') * temp + (product_str[i+j] - '0'));
                product_str[i+j] = carry_temp%10 + '0';
                carry_temp = carry_temp/10;
            }
            
            if(carry_temp != 0) {
                product_str[num1.size()+j] = carry_temp + '0';
            }
            
        }
        
        
        reverse(product_str.begin(), product_str.end());
        
        
        // remove those zero in the head of product_str
        // if they are all zeros, we can keep it
        int count_zero = 0;
        while((product_str[count_zero] == '0') && (count_zero < product_str.size()-1)) {
            count_zero += 1;
        }
        
        product_str.erase(0, count_zero);
        
        return product_str;
        
    }
};

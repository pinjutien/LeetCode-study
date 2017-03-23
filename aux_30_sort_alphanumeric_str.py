
def sort_aphanumeric_str(input_str):
    num_str = [str(i) for i in range(10)]

    result = ''

    is_num_previous = (input_str[0] in num_str)
    current_str = input_str[0]
    
    for i in range(1, len(input_str)):
        # import pdb; pdb.set_trace()
        is_num_current = (input_str[i] in num_str)

        if(is_num_current != is_num_previous):
            current_str = ''.join(sorted(current_str))
            result += current_str
            current_str = input_str[i]

        else:
            current_str += input_str[i]
            
        is_num_previous = is_num_current            

    if len(current_str) > 0:
        current_str = ''.join(sorted(current_str))
        result += current_str
        
        
    return result



if __name__ == "__main__":
    input_str = 'AZQF013452BAB'
    res = sort_aphanumeric_str(input_str)
    print(res)
    

    

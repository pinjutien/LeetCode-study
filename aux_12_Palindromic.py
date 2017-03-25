

def center_moving(left, right, input_str):
    while((left >=0) & (right <= len(input_str)) & (input_str[left] == input_str[right])):
        left -=1
        right +=1
        
    return input_str[left+1:right]



def largest_palindrom_str(input_str):

    if(len(input_str) == 0 | len(input_str) == 1):
        return input_str

    current_max = input_str[0]
    for i in range(len(input_str)-1):

        s1 = center_moving(i, i, input_str)
        if (len(s1) > len(current_max)):
            current_max = s1

        s2 = center_moving(i, i+1, input_str)
        if (len(s2) > len(current_max)):
            current_max = s2


    return current_max



if __name__ == "__main__":
    input_str = "ABXBAT"
    print(largest_palindrom_str(input_str))

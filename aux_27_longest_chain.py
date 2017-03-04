import numpy as np


def longest_chain(input_data):
    
    # sort the input_array by the length of element
    input_array = input_data.copy()
    input_array.sort(key = lambda x: len(x))

    hash_table = {}
    chain_array = {}

    # hash_table: {element, index}, it store the current (element, index) pair
    hash_table[input_array[0]] =  0

    # chain_array[i]: the longest chain from input_data[0] to input_data[j]
    chain_array[0]= 1
    answer = chain_array[0]
    
    for i in range(1, len(input_array)):
        # at every element, we initialize the chain_array
        chain_array[i] = 1
        element_str = input_array[i]

        # for every element, by removing the char one-by-one, we check
        # if the element after truncating one char exist in the hash_table.
        # if it did, we upated the chain array
        for j in range(len(element_str)):
            temp_str = element_str[:j] + element_str[j+1:]
            if (temp_str in hash_table):
                chain_array[i] = max(chain_array[i], chain_array[hash_table[temp_str]] + 1)
        
        
        answer = max(answer, chain_array[i])
        hash_table[element_str] = i

    
    return answer


if __name__ == "__main__":
    input_data = ['abcd', 'bcd', 'bd', 'defgh', 'cd', 'd']
    print("longest chain: ", longest_chain(input_data))
    
    


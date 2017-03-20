'''
Given a long length of input array, every element in the array are integers and between 1 and 10.

'''


def count_sort(input_array, k = 10):
    count_array = [0] * (k+1)

    # populuate count_array:
    # i-th element: it means the number of i in input array
    for i in input_array:
        print(i)
        count_array[i] += 1

    index = 0
    for i in range(len(count_array)):

        while (count_array[i] > 0):
            input_array[index] = i
            index += 1
            count_array[i] -= 1

    return input_array




if __name__ == "__main__":
    input_array = [3,3,3,4,3,2,1,1,2,6,7,8,9,10,6,6,7,7,9]
    print(count_sort(input_array, 10))

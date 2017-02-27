
# hash table for two sum
# time complexity: o(n)
# space complexity: o(n)


def two_sum(input_array, target):
    map_dict = {}

    for i in range(len(input_array)):
        comp = target - input_array[i]
        if (comp in map_dict):
            return i, map_dict[comp]

        map_dict[input_array[i]] = i

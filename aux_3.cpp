// Q: Bin packing Problem
// http://www.geeksforgeeks.org/bin-packing-problem-minimize-number-of-used-bins/
// https://en.wikipedia.org/wiki/Multiprocessor_scheduling
#include <iostream>
#include <vector>
using std::vector;

int min_num_bins( vector<int> element_input, int bin_size) {
  // sort the input vector; increasing order
  sort(element_input.begin(), element_input.end());

  int nums_element = element_input.size();
  int remaining_bin_size = bin_size;
  int bin_index = 0;
  for (int i = 0; i < nums_element; i++) {
    if (element_input[i] > remaining_bin_size) {
      bin_index += 1;
      remaining_bin_size = bin_size - element_input[i];
    }
    else {
      remaining_bin_size -= element_input[i];
    }
  }

  return bin_index;

}


int main()
{
  int array[] = {3, 34, 4, 12};
  int bin_size = 10;
  int size_of_array = sizeof(array)/sizeof(array[0]);
  vector<int> vector_input(array, array + size_of_array);
  cout << min_num_bins(vector_input, bin_size);


}

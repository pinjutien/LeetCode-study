#include <isotream>
#include <climits>
#include <cstdlib>

using namespace std;

// https://en.wikipedia.org/wiki/Quickselect
// http://www.geeksforgeeks.org/kth-smallestlargest-element-unsorted-array-set-2-expected-linear-time/

/*
Class	Selection algorithm
Data structure	Array
Worst-case performance	О(n2)::
 if bad pivots are consistently chosen, such as decreasing by only a single element each time, then worst-case performance is quadratic: O(n2). This occurs for example in searching for the maximum element of a set, using the first element as the pivot, and having sorted data.

Best-case performance	О(n)
Average performance	O(n)
*/

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}



int partition(int array[], int left_index, int right_index, int pivot_index) {

  int pivot_value = array[pivot_index];
  // move the piovt value in the end of array
  swap(&array[pivot_index], &array[right_index]);
  // we use store_index as a index which describing the current index which is smaller than pivot_value
  int store_index = left_index;
  
  for (int i = left; i <= right_index -1; i++) {
    if (array[i] < pivot_value) {
      swap(&array[store_index], &array[i]);
      store_index += 1;
    }
  }

  // now move the pivot value in the position that its left-hand side are smaller than itself.
  // right hand side are larger than itself.
  swap(&array[store_index], &array[right]);
  return store_index;
  
}


int select_kth_element(int array[], int left_index, int right_index, int k) {
  
  if (left == right) return array[left];

  pivot_index = rand() %(right_index - left_index + 1);

  current_index = partition(array, left_index, right_index, pivot_index);

  if (k == current_index) {
    return array[k];
  }
  else if (k < current_index) {
    return select_kth_element(array, left_index, current_index -1, k);
  }
  else {
    return select_kth_element(array, current_index +1, right_index, k);
  }

}

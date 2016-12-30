// http://www.geeksforgeeks.org/median-of-stream-of-integers-running-integers/
#include <iostream>
using namespace std;

// use two heaps to find the median
// left side: max heap; right side: min heap
// If x is smaller than effective_median (ie on the left side), x is populated into max heap. If greater, populated into min heap.
// In the processing of populating in coming elemenet, the difference of the sizes of these two heaps is at most 1.
// If these two heaps have the same size, the effective_median is the average of their root.
// If not, the effective_median is the root of heap with larger size.

int getMedian(int x, int effective_median, Heap &left_heap, Heap &right_heap) {

  // the size of left_heap is greater than the size of right_heap
  if (left_heap.get_count() > right_heap.get_count()) {
    // x must be in the left heap. But, in order not to increase the size difference between left-heap and right-heap, 1) we extract the root of left-heap and insert it to right-heap. 2) we insert x into left-heap.
    if(x < effective_median) {
      right_heap.Insert(left_heap.ExtractTop());
      right_heap.Insert(x);
    }
    else {
      right_heap.Insert(x);
    }
    effective_median = Average(left_heap.GetTop(), right_heap.GetTop());
  }

  // the size of left_heap is the same as the size of right_heap
  if (left_heap.get_count() == right_heap.get_count()) {
    if(x < effective_median) {
      left_heap.Insert(x);
      effective_median = left_heap.GetTop();
    }
    else {
      right_heap.Insert(x);
      effective_median = right_heap.GetTop();
    }
  }

  // the size of left_heap is smaller than the size of right_heap
  if (left_heap.get_count() < right_heap.get_count()) {

    if(x < effective_median) {
      left_heap.Insert(x);
    }
    else {
      left_heap.Insert(right_heap.ExtractTop());
      right_heap.Insert(x);
    }

    effective_median = Average(left_heap.GetTop(), right_heap.GetTop());
  }

  return effective_median;
}


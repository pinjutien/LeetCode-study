// Q: Detect if a subset from a given set of N non-negative integers sums upto a given value S.
// ref: https://www.quora.com/What-are-the-top-10-most-popular-dynamic-programming-problems-among-interviewers
// ref: http://www.geeksforgeeks.org/dynamic-programming-subset-sum-problem/

#include <iostream>
using std::min;

// this method is straightforward. recursively
bool FindSubset_v1(int array[], int size_of_array, int target_sum) {
  if ((target_sum == 0) && (size_of_array == 0)) {
    return true;
  }


  if ((target_sum != 0) && (size_of_array == 0)) {
    return false;
  }

  // FindSubset_v1(array, size_of_array -1, target_sum): the last element is used to get target_sum.
  // FindSubset_v1(array, size_of_array -1, target_sum - array[size_of_array -1]) : the last element is NOT used to get target_sum

  return (FindSubset_v1(array, size_of_array -1, target_sum) || FindSubset_v1(array, size_of_array -1, target_sum - array[size_of_array -1])) ;

}

// this method is Dynamic programming.
bool FindSubset_v1(int array[], int size_of_array, int target_sum) {
  bool table[size_of_array + 1][target_sum + 1];
  
  for (int i = 0; i <= size_of_array; i++) {
    table[i][0] = true;
  }

  for (int j = 1; j <= target_sum ; j++) {
    table[0][j] = false;
  }

  for (int i = 1; i <= size_of_array; i++) {
    for (int j = 1; j <= target_sum ; j++) {
      table[i][j] = table[i-1][j];
      int last_target_sum = j - array[i];
      if (last_target_sum >= 0) {
	table[i][j] =  ((table[i][j]) || (table[i-1][last_target_sum]));
      }
    }
  }

  return table[size_of_array][target_sum];
}



int main()
{
  int array[] = {3, 34, 4, 12};
  int target_sum = 9;
  int size_of_array = sizeof(array)/sizeof(array[0]);
  cout << FindSubset_v1(array, size_of_array, target_sum);


}

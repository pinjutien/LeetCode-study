#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>

using namespace std;
std::vector;


vector<int> find3numbers(vector<int> A, int N) {
  int *smaller = new int[N];
  int *greater = new int[N];
  vector<int> result;

  // construct a smaller array which store the index that is smaller than A[i]
  // if A[i] < A[min], we populate smaller[i] by -1 because there is no element smaller than A[i]
  // then update min = i
  int min = 0;
  smaller[0] = -1;
  for (int i = 1; i< N; i++) {
    if(A.at(i) <= A.at(min)) {
      min = i;
      smaller[i] = -1;
    }
    else {
      smaller[i] = min;
    }
  }

  // construct a greater array which store the index that is greater than A[i]
  // if A[i] > A[max], we populate greater[i] by -1 because there is no element greater than A[i]
  // then update max = i
  int mmax = N-1;
  greater[N-1] = -1;
  for (int i = N-2; i >= 0; i--) {
    if(A.at(i) >= A.at(max)) {
      max = i;
      greater[i] = -1;
    }
    else {
      greater[i] = max;
    }
  }


  for (int j = 0; j < N; j++) {
    if ((greater[i] != -1) & (smaller[i] != -1) & (result.size() <= 3)) {
      result.push_back(A.at(i));
    }
    else {
      break;
    }
  }

  return result;
}


int main() {

  int arr[] = {12, 11, 10, 5, 6, 2, 30};
  vector<int> vec_A(arr, arr+ sizeof(arr)/sizeof(arr[0]));
  vector<int> result;
  result =  find3numbers(vec_A, vec_A.size());

  return 0;
}



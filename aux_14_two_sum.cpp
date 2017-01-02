#include <stdio.h>
#include <stdlib.h>
#include <unordered_map>
#include <vector>


using namespace std;
typedef std:: unordered_map<int, int> mymap;
// std:: vector<mymap> myvector;

vector<mymap> two_sum_function(int arr[], int target) {
  int n = sizeof(arr)/sizeof(arr[0]);
  vector<mymap> result;
  mymap element_dict;
  for (int i = 0; i < n; i++) {
    element_dict[arr[i]] = i;
  }

  for (int i = 0; i < n; i++) {
    int temp = target - arr[i];
    if (element_dict.count(temp) >=1 ) {
      result.push_back({arr[i], temp});
    }
  }
  
  return result;
}


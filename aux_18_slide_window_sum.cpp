#include <isotream>
#include <vector>
using namespace std;

// sliding window sum
// http://siyang2notleetcode.blogspot.com/2015/02/sliding-window-sum.html
// given an array: [1, 2, 3, 4]
// window size = 2
// [1, 2] : 3
// [2, 3] : 5
// [3, 4] : 7
// => [3, 5, 7]

vector<int> slide_windows_sum(vector<int> nums, int w_size) {
  int n_size = nums.size();
  int current_sum = 0;
  vector<int> result;
  
  for (int i = 0; i < n_size; i++ ) {

    current_sum += nums[i];
    
    if (i == w_size-1) {
      result.push_back(current_sum);
      
    }
    
    if (i > w_size-1) {
      current_sum -= nums[i - w_size];
      result.push_back(current_sum);
    }

  }
  
  return result;

}


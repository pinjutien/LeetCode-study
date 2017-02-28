// ref: http://www.geeksforgeeks.org/write-a-c-program-to-print-all-permutations-of-a-given-string/
// https://brilliant.org/wiki/recursive-backtracking/
// 'abc' -> 'abc', 'acb', 'bac', 'bca', 'cab', 'cba'


class Solution {
public:
    vector<vector<int>> permute_utility(vector<int>& nums, int left_index, int right_index, vector<vector<int>>& solutions) {

      // when left_index is equal to right_index, it means no permutation needed.
      if (left_index == right_index) {
	solutions.push_back(nums);
	return solutions;
      }
      else {
	// left_index, right_index are the permutation index
	for (int i = left_index; i <= right_index; i++) {
	  swap(nums[left_index], nums[i]);
	  permute_utility(nums, left_index+1, right_index, solutions);
	  // backtracking
	  swap(nums[left_index], nums[i]);
	}
      }
    
      // return null vector
      return {};
}




  vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> solutions;
    int size_nums  = nums.size();
    permute_utility(nums, 0, size_nums-1, solutions);
    return solutions;  
  }
};

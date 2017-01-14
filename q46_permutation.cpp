// ref: http://www.geeksforgeeks.org/write-a-c-program-to-print-all-permutations-of-a-given-string/
// https://brilliant.org/wiki/recursive-backtracking/
class Solution {
public:
    vector<vector<int>> permute_utility(vector<int>& nums, int left_index, int right_index, vector<vector<int>>& solutions) {
        if (left_index == right_index) {
            solutions.push_back(nums);
            return solutions;
        }
        else {
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

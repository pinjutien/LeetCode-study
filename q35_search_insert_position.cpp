class Solution {
public:

    int find_target(vector<int>& nums, int target, int left_index, int right_index) {
        
        if (nums.size() == 1) {
            if (target > nums[0]) return 1;
            return 0;
        }
        
        if (right_index >= left_index) {
            int middle_index = (right_index + left_index)/2;
            int middle_element = nums[middle_index];
            
            if (target == middle_element) {
                return middle_index;
            }            
            
            if (target < middle_element) {
                return find_target(nums, target, left_index, middle_index-1);
            }
            
            return find_target(nums, target, middle_index+1, right_index);
        }
        
        if (target <= nums[right_index+1]) return left_index;
        
        
        return right_index+1;
    }

    int searchInsert(vector<int>& nums, int target) {
        return find_target(nums, target, 0, nums.size()-1);
    }
};

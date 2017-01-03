class Solution {
public:
    // binary search
    // if not found, return -1
    // else, return the index of the found element.
    int find_target(vector<int>& nums, int target, int left_index, int right_index) {
        if(right_index >= left_index) {
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
        
        return -1;
        
        
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int size_of_array = nums.size();
        int target_index;
        vector<int> result;
        // we use binary search to find the index of the target element.
        // then, start from the target_index and search left- and right-side to check
        // if there is other element the same as target.

        target_index = find_target(nums, target, 0, size_of_array-1);
        if ((target_index == -1) | (nums.size() == 0 )) {
            result.push_back(-1);
            result.push_back(-1);
            return result;
        }

        int left_index, right_index;
        left_index = target_index;
        right_index = target_index;
            
        while((nums[left_index] == target) & (left_index >= 0)) {
            left_index -= 1;
        }

        while((nums[right_index] == target) & (right_index < size_of_array)) {
            right_index += 1;
        }

        left_index += 1;
        right_index -= 1;
        result.push_back(left_index);
        result.push_back(right_index);
        return result;
    }
};

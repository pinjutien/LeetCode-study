
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int array_size = nums.size();
        //  i + nums[i] : the max_index i-th element can achieve.
        // to reach i-th elemet, max_index 
        int max_len = 0;
        for (int i = 0; i < array_size; i++) {
            
            // it means i-th element can not be reached.
            if ((i > max_len) || (max_len > array_size-1)) {
                break;
            }
            
            max_len = max(i+nums[i], max_len);
        }
        
        
        if ((array_size-1) <= max_len) return true;
        return false;
        
        
    }
};

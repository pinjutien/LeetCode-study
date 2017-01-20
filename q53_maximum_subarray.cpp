// Kadane’s Algorithm

class Solution {

public:
    int maxSubArray(vector<int>& nums) {
      
      if (nums.size() == 1) return nums[0];
      int num_size = nums.size();
      
      int current_max = nums[0];
      int current_sum = nums[0];
      
      for (int i = 1; i < num_size; i++) {

	// current_sum: keep track of sum. when it become negative, we upated it using the current element.
	if (current_sum < 0 ) {
	  current_sum = nums[i];
	}
	else {
	  current_sum += nums[i];
	}
            
	if (current_sum > current_max) {
	  current_max = current_sum;
	}
	
      }

        return current_max;
        
    }
};

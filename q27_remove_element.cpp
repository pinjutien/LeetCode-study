class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int nums_size = nums.size();
        if (nums_size == 0) {return 0;}
        int k = 0;
        
        for (int i = 0; i < nums_size; i++) {
            if (nums[i] != val) {
                nums[k] = nums[i];
                k = k + 1;
            }
        }
        
        return k;
        
    }
};
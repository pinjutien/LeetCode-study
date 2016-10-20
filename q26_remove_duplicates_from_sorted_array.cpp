class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int> result;
        int nums_size = nums.size();
        if (nums_size == 0) {return 0;}
        // k: the current index without duplicate elements in nums.
        // so, k+1 means the current length of nums without duplicates elements.
        int k = 0;
        int i = 0;
        for (int i = 1; i < nums_size; i++) {
            if (nums[i] != nums[i-1]) {
                k = k +1;
                nums[k] = nums[i];
            }
        }
        return k+1;
    }
};
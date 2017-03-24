// ref:
// http://fisherlei.blogspot.com/2013/01/leetcode-sort-colors.html


class Solution {
public:
    void sortColors(vector<int>& nums) {
        // red, while, blue are represented by 0, 1, 2
        if ((nums.size() == 0) || (nums.size() == 1)) return;
        int red_index = 0;
        int blue_index = nums.size() -1;
        int i = 0;
        while (i <= blue_index) {
            if (nums[i] == 0) {
                swap(nums[i], nums[red_index]);
                i+=1;
                red_index+=1;
                continue;
            }
            
            if (nums[i] == 2) {
                swap(nums[i], nums[blue_index]);
                blue_index -= 1;
                continue;
            }
            
            i+=1;
            
            
        }
        
        
    }
};

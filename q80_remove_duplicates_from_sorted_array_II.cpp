class Solution {
public:
// http://bangbingsyb.blogspot.com/2014/11/leetcode-remove-duplicates-from-sorted.html
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        
        if (n <=2 ) return n;
        
        // end denote the duplicates element.

        int end = 1;
        
        for (int i = 2; i < n; i++) {
            // if nums[i] == nums[end -1], it also implies nmus[end] = nums[i]
            // so, we just need to check nums[i] vs nums[end-1]
            if (nums[i] != nums[end-1]) {
                end += 1;
                nums[end] = nums[i];
            }
            
        }
        
        return end+1;
        
        
    }
};

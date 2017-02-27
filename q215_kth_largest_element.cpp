// https://leetcode.com/problems/kth-largest-element-in-an-array/?tab=Solutions
// http://www.geeksforgeeks.org/kth-smallestlargest-element-unsorted-array/
// http://www.geeksforgeeks.org/kth-smallestlargest-element-unsorted-array-set-2-expected-linear-time/

class Solution {
private:
    int heap_size;
    
public:
    int left_child_index(int i ) {
        return 2*i + 1;
    }
    int right_child_index(int i ) {
        return 2*i + 2;
    }


    void max_heapify(vector<int>& nums, int i) {
        int l = left_child_index(i);
        int r = right_child_index(i);
        int largest = i;
        if ((nums[l] > nums[largest]) && (l < heap_size)) largest = l;
        if ((nums[r] > nums[largest]) && (r < heap_size)) largest = r;
        
        if (largest != i) {
            swap(nums[largest], nums[i]);
            max_heapify(nums, largest);
        }
        
    }

    void build_heap(vector<int>& nums) {

        int heap_size = nums.size();
        for (int i = (heap_size/2) -1; i >=0; i--) {
            max_heapify(nums, i);
        }
    }

    int findKthLargest(vector<int>& nums, int k) {
        build_heap(nums);
        for (int i = 0; i < k; i++ ) {
            swap(nums[0], nums[heap_size -1]);
            heap_size -= 1;
            max_heapify(nums, 0);
            
        }
        return nums[heap_size];
    }
};

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
bool decreasing_function(int i, int j) {return (j > i);}

class Solution {
public:
	
	void nextPermutation(vector<int>& nums) {
		// assume the indexs: 0 to n-1
		// 1. find the first element i which is greater than (i-1) element.
		//    it makes us to find the key point to decide where to find the next greater one.
		//    if the element keep decreasing, there is no way that the greater permutation exist.
		// 2. make the vector between i and n-1 increasing.
		// 3. find the first larger element between i and n-1 than (i-1). Then, swap (i-1) and that.
		
		
		// 1. find the first element i which is greater than (i-1) element.
		for (int i = nums.size()-1; i > 0; i--) {
			if (nums[i] > nums[i-1]) break;
		}
		
		
		// 2. to make i to n-1 increasing order
		reverse(nums.begin()+i, nums.end());
		
		int temp_index = i;
		while (nums[i-1] >= nums[temp_index]) {
			temp_index++;
		}
		
		swap(nums[i-1], nums[temp_index]);
		
	}
	
};

int main() {
	int arr[4] = {1,5,3,2};
	int len_arr = sizeof(arr)/sizeof(arr[0]);
	std::vector<int> vec_in(arr, arr+len_arr);
	Solution solution;
	solution.nextPermutation(vec_in);
	for (int i = 0; i < vec_in.size(); i++) {
		cout << vec_in[i] << " ";
		
	}
	cout << "\n";
	
}


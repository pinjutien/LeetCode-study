
/*

input:
nums = [1,2,3]

output:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]


ans:

lets start from a empty one and keep adding one element at a time into every element in previous list.

[]
[], [1] : add 1 in previous list
[], [1], [2], [1,2]: add 2 in previous list

 */


class Solution {

public:
  
  vector<vector<int>> subsets(vector<int> &nums) {
    vector<vector<int>> result;
    vector<int> temp;

    result.push_back(temp);
    sorted(nums.begin(), nums.end());

    
    for (int i =0; i< nums.size(); i++) {
      int n = result.size();
      for (int j = 0; j < n; j++) {
	temp = result[j];
	temp.push_back(nums[i]);
	result.push_back(temp);

      }

    }

    return result;
    
  }



}

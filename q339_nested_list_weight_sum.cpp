// reference: http://www.jiuzhang.com/solutions/nested-list-weight-sum/
// http://blog.csdn.net/qq508618087/article/details/51014943

class Solution {
public:

  int weighted_sum_helper(const vector<NestedInteger>& nested_list, int depth) {
    int sum = 0;
    for (auto element: nested_list) {
      if (element.IsInteger()) {
	sum += depth * element.getInetger();
      }
      else {
	sum += weighted_sum_helper(element.getList(), depth+1);
      }

    }
    return sum;

  }
  
  int weigth_sum_by_depth(const vector<NestedInteger>& nested_list) {
    return nweighted_sum_helper(nested_list, 1);
  }



}

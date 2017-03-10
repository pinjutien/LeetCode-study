// backtracking solution:
// ref: https://leetcode.com/discuss/questions/oj/generate-parentheses
// https://discuss.leetcode.com/topic/4485/concise-recursive-c-solution/9

class Solution {
public:
  
  vector<string> generateParenthesis(int n) {
    vector<string> result;
    util(result, n, n, "", 0);
    return result;
    
  }
  
  void util(vector<string>& result, int m, int n, string temp, int counter) {
    if (counter < 0) return;
    
    if (m == 0 && n == 0){
      result.push_back(temp);
      return;
    }
    if (m > 0) {
      counter += 1;
      util(result, m-1, n, temp + "(", counter);
    }
    if (n > 0) {
      counter -= 1;
      util(result, m, n-1, temp + ")", counter);
    }
  }
	
	
};

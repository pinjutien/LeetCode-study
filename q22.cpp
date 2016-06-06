// backtracking solution:
// ref: https://leetcode.com/discuss/questions/oj/generate-parentheses

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        util(result, n, n, "");
        return result;
		
    }
    void util(vector<string>& result, int m, int n, string temp) {
        if (m == 0 && n == 0){
            result.push_back(temp);
            return;
        }
        if (m > 0) {
            util(result, m-1, n, temp + "(");
        }
        if (m < n) {
            util(result, m, n-1, temp + ")");
        }
    }
	
	
};
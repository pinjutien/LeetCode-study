class Solution {
public:
    // ref: http://bangbingsyb.blogspot.com/2014/11/leetcode-combination-sum-i-ii.html
    void find_target_sum(vector<int>& candidates, int start_index, int target, vector<int>& solution,vector<vector<int>>& all_solutions) {
        
        if (target == 0) {
            all_solutions.push_back(solution);
            return;
        }
        
        for (int i = start_index; i < candidates.size(); i++) {
            
            // skip the i-th element if i- and (i-1)- elements are the same
            if (candidates[i] == candidates[i-1] & i > start_index) {
                continue;
            }
            
            if (candidates[i] <= target) {
                solution.push_back(candidates[i]);
                find_target_sum(candidates, i, target - candidates[i], solution, all_solutions);
                solution.pop_back();
            }
            
        }
        
        
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> all_solutions;
        vector<int> solution;
        sort(candidates.begin(), candidates.end());
        find_target_sum(candidates, 0, target, solution, all_solutions);
        return all_solutions;
    }
};
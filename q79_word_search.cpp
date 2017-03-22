// ref: http://bangbingsyb.blogspot.com/2014/11/leetcode-word-search.html

class Solution {
public:
    // index: it is used to track if we reach the end of word
    bool find_match(vector<vector<char>>& board, vector<vector<bool>>& is_visited, string word, int row, int col, int index) {
        
        if (index == word.size()) return true;
        
        if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size() || is_visited[row][col] || board[row][col] != word[index]) {
            
            return false;
        }
        
        
        is_visited[row][col] = true;
        
        if(find_match(board, is_visited, word, row + 1, col, index + 1)) return true;
        if(find_match(board, is_visited, word, row - 1, col, index + 1)) return true;
        if(find_match(board, is_visited, word, row, col + 1, index + 1)) return true;
        if(find_match(board, is_visited, word, row, col -1, index + 1)) return true;
        is_visited[row][col] = false;
        
        return false;
    }


    bool exist(vector<vector<char>>& board, string word) {
        
        if (board.empty() || board[0].empty()) return false;
        vector<vector<bool>> is_visited(board.size(), vector<bool>(board[0].size(), false));
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if(find_match(board, is_visited, word, i, j, 0)) return true;
            }
        }
        
        return false;
    }
};

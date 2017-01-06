class Solution {
public:
    
    bool has_duplicates(vector<vector<char>>& board, int start_row, int end_row, int start_col, int end_col) {
        
        bool is_present[9 + 1] = {false};
        int number;
        
        for (int i = start_row; i <= end_row; i++){
            for (int j = start_col; j <= start_col; j++) {
                
                
                if (board[i][j] == '.') {
                    number = 0;
                }
                else {
                    number = board[i][j] - '0';
                }
                
                if (is_present[number] == true & number != 0) {
                    return true; 
                }
                is_present[number] = true;
            } 
        }
        
        return false;
    }


    // check if every row/column has duplicate elements.
    bool isValidSudoku(vector<vector<char>>& board) {
        
        // check row
        for (int i = 0; i < board.size(); i++) {
            if (has_duplicates(board, i, i, 0, board.size()-1)) {
                cout << "row false " << i << "\n";
                return false;
            }
        }

        // check column
        for (int j = 0; j < board.size(); j++) {
            if (has_duplicates(board, 0, board.size()-1, j, j)) {
                cout << "column false " << "\n";
                return false;
            }
        }        
        
        
        // check square
        int square_size = sqrt(board.size());
        for (int i = 0; i < square_size; i++) {
            for (int j = 0; j < square_size; j++) {
                
                if (has_duplicates(board, square_size *i, square_size *(i+1) -1,square_size *j, square_size *(j+1) -1)) {
                    cout << "square false" << "\n";
                    return false;
                }
                                
            }
        }
        
        return true;
        
    }
};

class Solution {
public:
    void swap(int &a, int &b) {
        int temp = b;
        b = a;
        a = temp;
        
    }

    // http://fisherlei.blogspot.com/2013/01/leetcode-rotate-image.html
    void rotate(vector<vector<int>>& matrix) {
        int rank_matrix = matrix.size();
        
        // 1. flip corredpong to x=y
        for (int i = 0; i < rank_matrix-1; i++) {
            for (int j = 0; j < rank_matrix - i; j++) {
                swap(matrix[i][j], matrix[rank_matrix -1 - j][rank_matrix -1 - i]);
                
            }
        }
        
        // 2. flip the horizontal line
        for (int i = 0; i < rank_matrix/2; i++) {
            for (int j = 0; j < rank_matrix; j++) {
                swap(matrix[i][j],matrix[rank_matrix - 1 - i][j]);
            }
            
        }
        
        
    }
};

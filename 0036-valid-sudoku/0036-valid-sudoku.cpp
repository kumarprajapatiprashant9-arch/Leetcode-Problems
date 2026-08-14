class Solution {
public:

    bool valid(vector<vector<char>>& board, int row, int col){

        for(int i = 0 ; i < board.size(); i++){

            // This checks for the column
            if(board[row][i] == board[row][col] && i != col){
                return false;
            }

            // This checks for the row
            if(board[i][col] == board[row][col] && i != row){
                return false;
            }

            // This checks for the sub-box
            int r = (row / 3)*3 + (i / 3);
            int c = (col / 3)*3 + (i % 3);

            if(board[r][c] == board[row][col] && (r != row || c != col)){
                return false;
            }
        }

        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){

                if(board[i][j] != '.'){
                    if(valid(board, i, j) == false){
                        return false;
                    }
                }
            }
        }
        \
        return true;
    }
};
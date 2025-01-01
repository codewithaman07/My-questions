class Solution {
public:
    bool valid(vector<vector<char>>&board, int i, int j, char c){
        for(int k = 0; k<9; k++){
            if(board[k][j] == c) return 0;
            if(board[i][k] == c) return 0;
            if(board[3*(i/3)+k/3][3*(j/3)+k%3] == c) return 0;
        }
        return 1;
    }
    bool solve(vector<vector<char>>&board){
        for(int i = 0; i<9; i++){
            for(int j = 0; j<9; j++){
                if(board[i][j] == '.'){
                    for(char c = '1'; c<='9'; c++){
                        if(valid(board, i, j, c)){
                            board[i][j] = c;
                            if(solve(board)) return 1;
                            else board[i][j] = '.';
                        }
                    }
                    return 0;
                }
            }
        }
        return 1;
    }
    void solveSudoku(vector<vector<char>>& board) {
       solve(board);
    }
};
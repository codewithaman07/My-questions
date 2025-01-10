class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<set<char>>r(9), c(9), temp(9);
        for(int i = 0; i<9; i++){
            for(int j = 0; j<9; j++){
                if(board[i][j] != '.'){
                    char ch = board[i][j];
                    int x = 3*(i/3)+ (j/3);
                    if(r[i].count(ch) || c[j].count(ch) || temp[x].count(ch)) return 0;
                    r[i].insert(ch);
                    c[j].insert(ch);
                    temp[x].insert(ch);
                }
            }
        }
        return 1;
    }
};
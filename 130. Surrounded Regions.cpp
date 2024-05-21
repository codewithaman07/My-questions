class Solution {
public:
    void dfs(vector<vector<char>> &board, vector<vector<int>> &vis, int row, int col, 
    int drow[], int dcol[]){
        int n = board.size();
        int m = board[0].size();
        vis[row][col] = 1;
        for(int i = 0; i<4; i++){
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && 
            board[nrow][ncol] == 'O' && !vis[nrow][ncol]){
                dfs(board,vis,nrow,ncol,drow,dcol);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>>vis(n, vector<int>(m,0));
        int drow[4] = {-1,0,1,0};
        int dcol[4] = {0,1,0,-1};
        for(int j = 0; j<m; j++){
            if(!vis[0][j] && board[0][j] == 'O'){
                dfs(board,vis,0,j,drow,dcol);
            }
            if(!vis[n-1][j] && board[n-1][j] == 'O'){
                dfs(board,vis,n-1,j,drow,dcol);
            }
        }
        for(int i = 0; i<n; i++){
            if(!vis[i][0] && board[i][0] == 'O'){
                dfs(board,vis,i,0,drow,dcol);
            }
            if(!vis[i][m-1] && board[i][m-1] == 'O'){
                dfs(board, vis, i , m-1, drow, dcol);
            }
        }
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(!vis[i][j] && board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }
        return;
    }
};

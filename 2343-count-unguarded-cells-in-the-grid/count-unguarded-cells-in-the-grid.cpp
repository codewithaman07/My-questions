class Solution {
public:
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
    bool valid(int i,int j,int n,int m,vector<vector<int>>&grid){
        return i>=0 && i<n && j>=0 && j<m && grid[i][j]!=2 && grid[i][j]!=1;
    }
    int countUnguarded(int n,int m,vector<vector<int>>&guards,vector<vector<int>>&walls){
        vector<vector<int>> grid(n, vector<int>(m,0));
        // vector<vector<bool>> vis(n, vector<bool>(m,0));
        for(auto &g: guards) grid[g[0]][g[1]] = 1;
        for(auto &w: walls) grid[w[0]][w[1]] = 2;
        for(auto &g: guards){
            int gx = g[0], gy = g[1];
            for(int d=0; d<4; d++){
                int x = gx + dx[d], y = gy + dy[d];
                while(valid(x,y,n,m,grid)){
                    if(grid[x][y]==0) grid[x][y]=3;
                    x += dx[d];
                    y += dy[d];
                }
            }
        }
        int cnt = 0;
        for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(grid[i][j] == 0) cnt++;
        return cnt;
    }
};
class Solution {
public:
    int dx[8] = {-1,1,1,0,0,-1,-1,1};
    int dy[8] = {0,0,-1,1,-1,-1,1,1};
    bool valid(int n, int m, int i, int j, vector<vector<int>>&grid, vector<vector<int>>&vis){
        if(i>=0 && i<n && j>=0 && j<m && !grid[i][j] && !vis[i][j]) return 1;
        return 0;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        if(grid[0][0] || grid[n-1][m-1]) return -1;
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<tuple<int,int,int>>q;
        q.push({0,0,1});
        vis[0][0] = 1;
        while(!q.empty()){
            auto [x,y,d] = q.front();
            q.pop();
            if(x == n-1 && y == m-1) return d;
            for(int k = 0; k<8; k++){
                int nx = x+dx[k];
                int ny = y+dy[k];
                if(!valid(n,m,nx,ny,grid,vis)) continue;
                vis[nx][ny] = 1;
                q.push({nx,ny,d+1});
            }
        }
        return -1;
    }
};
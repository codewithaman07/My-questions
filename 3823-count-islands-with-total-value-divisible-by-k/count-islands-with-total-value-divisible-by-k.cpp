class Solution {
public:
    #define ll long long
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    ll bfs(vector<vector<int>>&grid, vector<vector<int>>&vis, int i, int j){
        ll sum = 0, n = grid.size(), m = grid[0].size();
        queue<pair<int,int>>q;
        q.push({i,j});
        vis[i][j] = 1;
        while(!q.empty()){
            auto [x, y] = q.front();
            vis[x][y] = 1;
            q.pop();
            sum+=grid[x][y];
            for(int k = 0; k<4; k++){
                ll nx = x+dx[k];
                ll ny = y+dy[k];
                if(nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny]>0 && !vis[nx][ny]){
                    q.push({nx,ny});
                    vis[nx][ny] = 1;
                }
            }
        }
        return sum;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int cnt = 0, n = grid.size(), m = grid[0].size();
        vector<vector<int>>vis(n, vector<int>(m,0));
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(!vis[i][j] && grid[i][j]>0){
                    int sum = bfs(grid,vis, i, j);
                    if(sum%k == 0) cnt++;
                }
            }
        }
        return cnt;
    }
};
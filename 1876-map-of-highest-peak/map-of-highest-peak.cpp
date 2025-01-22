class Solution {
public:
    bool check(int n, int m, int i, int j){
        return (i>=0 && i<n && j>=0 && j<m);
    }
    vector<vector<int>> highestPeak(vector<vector<int>>& grid) {
        int dx[4] = {0,0,1,-1};
        int dy[4] = {1,-1,0,0};
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>>ans(n, vector<int>(m, INT_MAX));
        vector<vector<bool>>vis(n, vector<bool>(m,0));
        queue<pair<int,int>>q;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j]){
                    q.push({i,j});
                    ans[i][j] = 0;
                    vis[i][j] = 1;
                }
            }
        }
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            int i = p.first;
            int j = p.second;
            int mini = INT_MAX;
            for(int k = 0; k<4; k++){
                int nr = i+dx[k];
                int nc = j+dy[k];
                if(check(n,m,nr,nc) && !vis[nr][nc]){
                    q.push({nr,nc});
                    vis[nr][nc] = 1;
                    ans[nr][nc] = ans[i][j]+1;
                }
                
            }
        }
        return ans;
    }
};
class Solution {
public:
    #define pp pair<int, pair<int,int>>
    bool check(int n, int m, int i, int j){
        return (i>=0 && i<n && j>=0 && j<m);
    }
    int trapRainWater(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int dx[4] = {0,0,1,-1};
        int dy[4] = {1,-1,0,0};
        vector<vector<bool>>vis(n, vector<bool>(m,0));
        priority_queue<pp, vector<pp>, greater<pp>>pq;
        for(int i = 0; i<n; i++){
            for(int j : {0, m-1}){
                pq.push({grid[i][j], {i,j}});
                vis[i][j] = 1;
            }
        }
        for(int j = 0; j<m; j++){
            for(int i : {0, n-1}){
                if(!vis[i][j]){
                    pq.push({grid[i][j], {i,j}});
                    vis[i][j] = 1;
                }
            }
        }
        int ans = 0;
        while(!pq.empty()){
            pp x = pq.top();
            pq.pop();
            int h = x.first;
            int i = x.second.first;
            int j = x.second.second;
            for(int r = 0; r<4; r++){
                int nr = i+dx[r];
                int nc = j+dy[r];
                if(check(n,m,nr,nc) && !vis[nr][nc]){
                    ans+= max(0, h-grid[nr][nc]);
                    int maxi = max(h, grid[nr][nc]);
                    pq.push({maxi, {nr,nc}});
                    vis[nr][nc] = 1;
                }
            }
        }
        return ans;
    }
};
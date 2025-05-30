class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n  = grid.size(), m = grid[0].size();
        queue<pair<int,int>>q;
        int cnt = 0, tot = 0, ans = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] != 0) tot++;
                if(grid[i][j] == 2) q.push({i,j});
            }
        }
        int dx[4] = {0,0,1,-1};
        int dy[4] = {1,-1,0,0};
        while(!q.empty()){
            int k = q.size();
            cnt+=k;
            while(k--){
                int x = q.front().first, y = q.front().second;
                q.pop();
                for(int i = 0; i<4; i++){
                    int nx = x+dx[i], ny = y+dy[i];
                    if(nx<0 || ny<0 || nx>=n || ny>=m || grid[nx][ny] != 1) continue;
                    if(grid[nx][ny] != 2){
                        grid[nx][ny] = 2;
                        q.push({nx,ny});
                    } 
                }
            }
            if(!q.empty()) ans++;
        }
        if(cnt != tot) return -1;
        else return ans;
    }
};
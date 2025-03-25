class Solution {
public:
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
    bool valid(int n, int m, int i, int j){
        if(i>=0 && i<n && j>=0 && j<m) return 1;
        return 0;
    }
    using P = pair<int,pair<int,int>>;
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        vector<vector<int>>dist(n, vector<int>(m,1e9));
        priority_queue<P, vector<P>, greater<P>>pq;
        pq.push({0,{0,0}});
        dist[0][0] = 0;
        while(!pq.empty()){
            auto node = pq.top();
            pq.pop();
            int x = node.second.first;
            int y = node.second.second;
            int dis = node.first;
            for(int k = 0; k<4; k++){
                int nx = x+dx[k];
                int ny = y+dy[k];
                if(!valid(n,m,nx,ny)) continue;
                int num = abs(heights[x][y]-heights[nx][ny]);
                num = max(num,dis);
                if(dist[nx][ny]>num){
                    dist[nx][ny] = num;
                    pq.push({num, {nx,ny}});
                }
            }
        }
        return (dist[n-1][m-1] == 1e9) ? -1 : dist[n-1][m-1];
    }
};
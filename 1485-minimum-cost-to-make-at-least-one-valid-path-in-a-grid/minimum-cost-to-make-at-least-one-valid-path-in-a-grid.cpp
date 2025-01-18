class Solution {
public:
    // At max cost can be m+n
    // create graph make a edge between all its vertices
    // do bfs from 0,0 to n-1,m-1;
    bool check(int nr, int nc, int n, int m){
        return (nr < n && nc < m && nr>=0 && nc>=0);
    }
    int wtcheck(int cr, int cc, int nr, int nc) {
        if (nr == cr && nc == cc + 1) return 1; 
        if (nr == cr && nc == cc - 1) return 2; 
        if (nr == cr + 1 && nc == cc) return 3; 
        if (nr == cr - 1 && nc == cc) return 4; 
        return -1;
    }

    int minCost(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int dx[4] = {0,0,1,-1};
        int dy[4] = {1,-1,0,0};
        vector<vector<pair<int,int>>>adj(n*m);
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                int idx = i*m + j; // converting 2D to 1D
                for(int k = 0; k<4; k++){
                    int nr = i+dx[k];
                    int nc = j+dy[k];
                    if(check(nr,nc,n,m)){
                        int temp = nr*m+nc;
                        if(wtcheck(i,j,nr,nc) == grid[i][j]) adj[idx].emplace_back(temp, 0);
                        else adj[idx].emplace_back(temp, 1);
                    }
                }
            }
        }
        vector<int>dist(n*m, INT_MAX);
        deque<int>dq;
        dist[0] = 0;
        dq.push_back(0);
        while(!dq.empty()){
            int current = dq.front();
            dq.pop_front();
            int cr = current/m;
            int cc = current%m;
            for (auto& [neighbor, weight] : adj[current]) {
                if (dist[current] + weight < dist[neighbor]) {
                    dist[neighbor] = dist[current] + weight;
                    if (weight == 0) dq.push_front(neighbor); 
                    else dq.push_back(neighbor);
                }
            }
        }
        return dist[n*m-1];
    }
};
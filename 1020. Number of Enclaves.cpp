class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size(); // Number of rows
        int m = grid[0].size(); // Number of columns
        vector<vector<int>> vis(n, vector<int>(m, 0)); // Visited array
        queue<pair<int, int>> q; // Queue for BFS

        // Mark all boundary land cells and start BFS from them
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(i == 0 || i == n-1 || j == 0 || j == m-1) { // Boundary cells
                    if(grid[i][j] == 1) { // Land cell
                        q.push({i, j}); // Add to queue
                        vis[i][j] = 1; // Mark as visited
                    }
                }
            }
        }

        // Directions for moving up, right, down, left
        int drow[4] = {-1, 0, 1, 0};
        int dcol[4] = {0, 1, 0, -1};

        // BFS from boundary land cells
        while(!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            // Explore all 4 possible directions
            for(int i = 0; i < 4; i++) {
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                // If the new cell is within bounds, a land cell, and not visited
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                   vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1) {
                    q.push({nrow, ncol}); // Add to queue
                    vis[nrow][ncol] = 1; // Mark as visited
                }
            }
        }

        // Count the number of enclaves
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(vis[i][j] == 0 && grid[i][j] == 1) { // Unvisited land cell
                    cnt++;
                }
            }
        }

        return cnt; // Return the number of enclaves
    }
};

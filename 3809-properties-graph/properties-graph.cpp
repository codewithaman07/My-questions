class Solution {
public:
    vector<int>parent;
    int find(int x){
        if(parent[x] != x){
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    void Union(int x, int y){
        int rx = find(x);
        int ry = find(y);
        if(rx != ry) parent[ry] = rx;
    }
    int fun(set<int>&a, set<int>&b){
        int cnt = 0;
        for(int num : a){
            if(b.count(num)) cnt++;
        }
        return cnt;
    }
    int numberOfComponents(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        vector<set<int>>nums(n);
        parent.resize(n);
        for(int i = 0; i<n; i++) parent[i] = i;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                nums[i].insert(grid[i][j]);
            }
        }
        for(int i = 0; i<n; i++){
            set<int>a = nums[i];
            for(int j = i+1; j<n; j++){
                set<int>b = nums[j];
                if(fun(a,b)>=k){
                    Union(i,j);
                }
            }
        }
        set<int>ans;
        for(int i = 0; i<n; i++) ans.insert(find(i));
        return ans.size();
    }
};
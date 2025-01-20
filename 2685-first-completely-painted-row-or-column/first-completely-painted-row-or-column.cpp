class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        unordered_map<int,int>row;
        unordered_map<int,int>col;
        unordered_map<int,pair<int,int>>grid;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                grid[mat[i][j]] = {i,j};
            }
        }
        // cout<<"n and m is "<<n<<" "<<m<<endl;
        bool fr = 0, fc = 0;
        for(int i = 0; i<arr.size(); i++){
            int num = arr[i];
            auto p = grid[num];
            // cout<<p.first<<" "<<p.second<<endl;
            row[p.first]++;
            if(row[p.first] == m) fr = 1;
            col[p.second]++;
            if(col[p.second] == n) fc = 1;
            // cout<<row[p.first]<<" "<<col[p.second]<<endl;
            if(fr || fc) return i;
        }
        return -1;
    }
};
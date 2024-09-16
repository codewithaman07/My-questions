class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& arr, int n, int m) {
        int x = arr.size();
        if(x!=n*m) return {};
        vector<vector<int>>ans;
        for(int i = 0; i<n*m; i+=m){
            vector<int>temp;
            for(int j = i; j<i+m; j++){
                temp.push_back(arr[j]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
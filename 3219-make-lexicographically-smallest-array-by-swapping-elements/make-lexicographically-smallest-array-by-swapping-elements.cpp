class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<pair<int,int>>temp(n);
        for(int i = 0; i<n; i++) temp[i] = {nums[i],i};
        sort(temp.begin(),temp.end());
        vector<int>arr;
        arr.push_back(temp[0].second);
        vector<vector<int>>x;
        for(int i = 0; i<n-1; i++){
            if(abs(temp[i].first - temp[i+1].first) > limit){
                sort(arr.begin(),arr.end());
                x.push_back(arr);
                arr.clear();
                arr.push_back(temp[i+1].second);
            }
            else arr.push_back(temp[i+1].second);
        }
        if(!arr.empty()){
            sort(arr.begin(),arr.end());
            x.push_back(arr);
        }
        int k = 0;
        for(int i = 0; i<x.size(); i++){
            for(int j = 0; j<x[i].size(); j++){
                temp[k++].second = x[i][j];
            }
        }
        vector<int>ans(n);
        for(int i = 0; i<n; i++){
            ans[temp[i].second] = temp[i].first;
        }
        return ans;
    }
};
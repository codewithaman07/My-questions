class Solution {
public:
    int maxi = 0, mini = INT_MAX;
    void dfs(int node, int parent, vector<vector<pair<int,int>>>&adj, vector<int>&nums, int pathsum, int s, int e, unordered_map<int,int>&mp ,vector<int>&path){
        int pred = mp.count(nums[node]) ? mp[nums[node]] : -1;
        while(s<=pred) pathsum-= path[s++];
        if(pathsum > maxi){
            maxi = pathsum;
            mini = e-s+1;
        }
        else if(pathsum == maxi) mini = min(mini, e-s+1);
        mp[nums[node]] = e;

        for(auto& [neighbor , len] : adj[node]){
            if(neighbor == parent) continue;
            path.push_back(len);
            dfs(neighbor, node, adj, nums, pathsum+len, s, e+1, mp, path);
            path.pop_back();
        }
        mp[nums[node]] = pred;
    }
    vector<int> longestSpecialPath(vector<vector<int>>& edges, vector<int>& nums) {
        int n = nums.size();
        vector<vector<pair<int,int>>>adj(n);
        for(auto &e : edges){
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0],e[2]});
        }
        vector<int>path;
        unordered_map<int,int>mp;
        dfs(0,-1,adj,nums,0,0,0,mp,path);
        return {maxi, mini};
    }
};
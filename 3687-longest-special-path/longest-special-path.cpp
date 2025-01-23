class Solution {
public:
    pair<int,int>ans;
    vector<int>depths;
    Solution() : depths(50001,0) {}

    void dfs(int node, int parent, vector<vector<pair<int,int>>>&adj, vector<int>&nums, int maxd, int currd,vector<int>&pre){
        int pred = exchange(depths[nums[node]], currd);
        maxd = max(maxd, pred);
        if (maxd < currd) {
            ans = min(ans, {-(pre.back() - pre[maxd]), currd - maxd});
        }
        for(auto& [neighbor, len] : adj[node]){
            if(neighbor == parent) continue;
            pre.push_back(pre.back()+len);
            dfs(neighbor, node, adj, nums, maxd, currd+1, pre);
            pre.pop_back();
        }
        depths[nums[node]] = pred;
    }

    vector<int> longestSpecialPath(vector<vector<int>>& edges, vector<int>& nums) {
        int n = nums.size();
        vector<vector<pair<int,int>>>adj(n);
        for(auto &e : edges){
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0],e[2]});
        }
        vector<int>pre{0};
        ans = {INT_MAX, INT_MAX};
        dfs(0,-1,adj,nums,0,1,pre);
        return {-ans.first, ans.second};
    }
};
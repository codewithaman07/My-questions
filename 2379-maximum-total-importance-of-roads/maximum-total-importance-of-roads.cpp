class Solution {
public:
    #define ll long long
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<ll>indegree(n,0);
        for(auto &e : roads){
            indegree[e[0]]++;
            indegree[e[1]]++;
        }
        vector<pair<ll,ll>>nodes;
        for(int i = 0; i<n; i++){
            nodes.push_back({indegree[i], i});
        }
        sort(nodes.begin(),nodes.end());
        ll ans = 0;
        for(int i = n-1; i>=0; i--){
            ans+=(nodes[i].first)*(i+1);
        }
        return ans;
    }
};
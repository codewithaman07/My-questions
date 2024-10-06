class Solution {
public:
    void dfs(int node, vector<int>&sus, vector<int>adj[]){
        sus[node] = 1;
        for(auto i : adj[node]){
            if(sus[i] == 0) dfs(i,sus,adj);
        }
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<int>adj[n];
        for(int i = 0; i<invocations.size(); i++){
            int a = invocations[i][0];
            int b = invocations[i][1];
            adj[a].push_back(b);
        }
        vector<int>temp;
        for(int i = 0; i<n; i++) temp.push_back(i);
        vector<int>ans;
        vector<int>sus(n,0);
        dfs(k,sus,adj);
        for(int i = 0; i<invocations.size(); i++){
            int a =invocations[i][0];
            int b =invocations[i][1];
            if(sus[a] == 0 && sus[b] == 1) return temp;
        }
        for(int i = 0; i<n; i++){
            if(sus[i] == 0) ans.push_back(i);
        }
        return ans;
    }
};
class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        unordered_map<int,unordered_set<int>>reachable;
        for(auto & it : prerequisites){
            reachable[it[1]].insert(it[0]);
        }
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(reachable[j].count(i)){
                    reachable[j].insert(reachable[i].begin(), reachable[i].end());
                }
            }
        }
        vector<bool>ans;
        for(auto & query : queries){
            ans.push_back(reachable[query[1]].count(query[0]));
        }
        return ans;
    }
};
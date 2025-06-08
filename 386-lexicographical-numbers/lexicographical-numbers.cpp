class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<string>temp;
        vector<int>ans;
        for(int i = 1; i<=n; i++){
            temp.push_back(to_string(i));
        }
        sort(temp.begin(),temp.end());
        for(auto i : temp) ans.push_back(stoi(i));
        return ans;
    }
};
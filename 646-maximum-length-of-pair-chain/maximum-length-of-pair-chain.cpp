class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end(), [](const vector<int>&a, const vector<int>&b){
            return a[1]<b[1];
        });
        int cnt = 0, prev = INT_MIN;
        for(auto &pair : pairs){
            if(pair[0] > prev){
                cnt++;
                prev = pair[1];
            }
        }
        return cnt;
    }
};
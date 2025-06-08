class Solution {
public:
    int maxSumDistinctTriplet(vector<int>& x, vector<int>& y) {
        int n = x.size();
        unordered_map<int,int>mp;
        for(int i = 0; i<n; i++){
            mp[x[i]] = max(mp[x[i]], y[i]);
        }
        if(mp.size()<3) return -1;
        vector<int>temp;
        for(auto &[x,y] : mp) temp.push_back(y);
        sort(temp.begin(),temp.end(), greater<int>());
        return temp[0]+temp[1]+temp[2];
    }
};
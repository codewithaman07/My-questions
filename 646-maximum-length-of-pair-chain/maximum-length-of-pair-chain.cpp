class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        vector<int>temp;
        sort(pairs.begin(),pairs.end());
        for(auto &num : pairs){
            auto it = lower_bound(temp.begin(),temp.end(), num[0]);
            if(it == temp.end()) temp.push_back(num[1]);
            else *it = min(*it, num[1]);
        }
        return temp.size();
    }
};
class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string>ans;
        int n = s.size();
        for(int i = 0; i<n; i+=k){
            string temp = s.substr(i,k);
            if(temp.size() < k) temp.append(k-temp.size(), fill);
            ans.push_back(temp);
        }
        return ans;
    }
};
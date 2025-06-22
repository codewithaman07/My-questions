class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string>ans;
        int n = s.size();
        for(int i = 0; i<n; i+=k){
            string temp;
            for(int j = i; j<min(i+k,n); j++){
                temp.push_back(s[j]);
            }
            if(temp.size() == k) ans.push_back(temp);
            else{
                int x = temp.size();
                for(int j = 0; j<k-x; j++) temp.push_back(fill);
                ans.push_back(temp);
            }
        }
        return ans;
    }
};
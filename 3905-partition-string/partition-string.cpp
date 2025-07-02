class Solution {
public:
    vector<string> partitionString(string s) {
        string temp;
        vector<string>ans;
        int n = s.size();
        unordered_set<string>st;
        for(char ch : s){
            temp.push_back(ch);
            if(!st.count(temp)){
                st.insert(temp);
                ans.push_back(temp);
                temp.clear();
            }
        }
        return ans;
    }
};
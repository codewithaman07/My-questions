class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        vector<string>ans;
        sort(folder.begin(),folder.end());
        string temp;
        for(string &s : folder){
            if(temp.empty() || s.compare(0, temp.size(), temp) != 0 || s[temp.size()] != '/'){
                ans.push_back(s);
                temp = s;
            }
        }
        return ans;
    }
};
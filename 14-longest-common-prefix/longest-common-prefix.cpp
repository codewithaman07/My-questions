class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";
        string pre = strs[0];
        int n = strs.size();
        for(int i = 1; i<n; i++){
            int j = 0;
            while(j<pre.size() && j<strs[i].size() && pre[j] == strs[i][j]) j++;
            pre = pre.substr(0,j);
            if(pre.empty()) return "";
        }
        return pre;
    }
};

// class Solution {
// public:
//     string longestCommonPrefix(vector<string>& strs) {
//         sort(strs.begin(),strs.end());
//         string ans;
//         string first = strs[0];
//         string last = strs[strs.size()-1];
//         for(int i = 0; i<min(first.size(),last.size()); i++){
//             if(first[i]==last[i]){
//                 ans+=first[i];
//             }
//             else{
//                 return ans;
//             }
//         }
//         return ans;
//     }
// };
class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size(), cnt = 0;
        for(int i = 0; i<n; i++){
            for(int j = i+1; j<n; j++){
                if(words[i].size() > words[j].size()) continue;
                int f1 = 1, f2 = 1, m = words[i].size();
                string temp = words[i];
                for(int k = 0; k<m; k++){
                    if(temp[k] != words[j][k]){
                        f1 = 0; 
                        break;
                    }
                }
                for(int k = 0; k<m; k++){
                    if(temp[m-1-k] != words[j][words[j].size()-1-k]){
                        f2 = 0;
                        break;
                    }
                }
                if(f1 && f2) cnt++;
            }
        }
        return cnt;
    }
};
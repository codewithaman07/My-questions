class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = shifts.size(), m = s.size();
        vector<int>diff(m,0), pre(m,0);
        for(int i = 0; i<n; i++){
            int l = shifts[i][0], r = shifts[i][1], dir = shifts[i][2];
            if(dir == 0){
                diff[l] += -1;
                if(r+1 < m) diff[r+1] += 1;
            }
            else if(dir == 1){
                diff[l] += 1;
                if(r+1 < m) diff[r+1] += -1;
            }
        }
        pre[0] = diff[0];
        for(int i = 1; i<m; i++) pre[i] = diff[i]+pre[i-1];
        for(int i = 0; i<m; i++){
            int num = (s[i]-'a'+pre[i])%26;
            if(num < 0) num+=26;
            s[i] = 'a'+num;
        }
        for(int i = 0; i<m; i++) cout<<pre[i]<<" ";
        return s;
    }
};
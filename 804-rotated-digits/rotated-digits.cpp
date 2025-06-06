class Solution {
public:
    int rotatedDigits(int n) {
        int cnt = 0;
        for(int i = 1; i<=n; i++){
            unordered_map<int,int>mp;
            for(int i = 0; i<=9; i++){
                if(i == 0 || i == 1 || i == 8) mp[i] = i;
                else if(i == 2) mp[i] = 5;
                else if(i == 5) mp[i] = 2;
                else if(i == 6) mp[i] = 9;
                else if(i == 9) mp[i] = 6;
                else mp[i] = -1;
            }
            string s = to_string(i);
            int temp = 0;
            int f = 0;
            for(int j = 0; j<s.size(); j++){
                int num = s[j]-'0';
                if(mp[num] == -1){
                    f = 1;
                    break;
                }
                temp = temp*10+mp[num];
            }
            if(f) continue;
            if(temp != i) cnt++;
        }
        return cnt;
    }
};
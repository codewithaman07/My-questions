class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int ans = 0;
        for(int i = low; i<=high; i++){
            string temp = to_string(i);
            int n = temp.size();
            if(n&1) continue;
            int x = 0, y = 0, j = 0;
            for(; j<n/2; j++) x+=temp[j]-'0';
            for(; j<n; j++) y+=temp[j]-'0';
            if(x == y) ans++;
        }
        return ans;
    }
};
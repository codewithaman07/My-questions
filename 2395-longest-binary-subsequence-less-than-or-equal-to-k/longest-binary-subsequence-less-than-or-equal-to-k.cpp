class Solution {
public:
    int longestSubsequence(string s, int k) {
        int n = s.size();
        int num = 0, cnt = 0, bits = 0;
        for(int i = n-1; i>=0; i--){
            if(s[i] == '0') cnt++;
            else{
                if(bits<31 &&(num+(1ll<<bits)<=k)){
                    cnt++;
                    num+=(1ll<<bits);
                }
            }
            bits++;
        }
        return cnt;
    }
};


// class Solution {
// public:
//     unordered_map<string,int>dp;
//     int solve(int i, int num, int len, string &s, int k){
//         int n = s.size();
//         if(num>k) return INT_MIN;
//         if(i>=n) return len;
//         string key = to_string(i) + "|" + to_string(num) + "|" + to_string(len);
//         if (dp.count(key)) return dp[key];
//         int np = solve(i+1,num,len,s,k);
//         int x = s[i]-'0';
//         int p = INT_MIN;
//         int temp = (num<<1)+x;
//         if(temp<=k) p = 1+solve(i+1,temp,len+1,s,k);
//         return dp[key] = max(p,np);
//     }
//     int longestSubsequence(string s, int k) {
//         return solve(0,0,0,s,k);
//     }
// };

// class Solution {
// public:
//     int fun(string s){
//         int n = s.size();
//         reverse(s.begin(), s.end());
//         int num = 0;
//         for(int i = 0; i<n; i++){
//             num+=(s[i] == '1' ? pow(2,i) : 0);
//         }
//         return num;
//     }
//     int solve(int i, string num, string &s, int k){
//         int n = s.size();
//         if(i>=n) return num.size();
//         int temp = fun(num+to_string(s[i]));
//         int p = INT_MIN;
//         if(temp<=k){
//             p = solve(i+1,num+s[i],s,k);
//         }
//         int np = solve(i+1,num,s,k);
//         return max(p,np);
//     }
//     int longestSubsequence(string s, int k) {
//         string num;
//         return solve(0,num,s,k);
//     }
// };
class Solution {
public:
    #define ll long long
    long long distributeCandies(int n, int limit) {
        ll ans = 0, mini = max(0,n-2*limit), maxi = min(n,limit);
        for(int i = mini; i<=maxi; i++){
            ll m = n-i;
            ll x = max(0ll, m-limit);
            ll y = min(m,1ll*limit);
            ans+=(y-x+1);
        }
        return ans;
    }
};

// class Solution {
// public:
//     #define ll long long
//     long long distributeCandies(int n, int limit) {
//         ll ans = 0;
//         for(int i = 0; i<=min(n,limit); i++){
//             for(int j = 0; j<=min(n-i,limit); j++){
//                 int k = n-i-j;
//                 if(i+j+k == n && k<=limit){
//                     ans++;
//                 }
//             }
//         }
//         return ans;
//     }
// };

// class Solution {
// public:
//     #define ll long long
//     ll dp[4][1000001];
//     ll solve(int child, int n, int limit){
//         if(child >= 3) return n == 0;
//         if(dp[child][n] != -1) return dp[child][n];
//         ll ans = 0;
//         for(int i = 0; i<=min(n,limit); i++){
//             ans+=solve(child+1,n-i,limit);
//         }
//         return dp[child][n] = ans;
//     }
//     long long distributeCandies(int n, int limit) {
//         memset(dp, -1, sizeof(dp));
//         return solve(0,n,limit);
//     }
// };

// class Solution {
// public:
//     #define ll long long
//     ll solve(int child, int n, int limit){
//         if(child >= 3){
//             if(n == 0) return 1;
//             return 0;
//         }
//         ll ans = 0;
//         for(int i = 0; i<=min(n,limit); i++){
//             ans+=solve(child+1, n-i, limit);
//         }
//         return ans;
//     }
//     long long distributeCandies(int n, int limit) {
//         return solve(0,n,limit);
//     }
// };
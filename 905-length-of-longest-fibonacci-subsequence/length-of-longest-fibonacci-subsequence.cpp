class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size(), ans = 0;
        vector<vector<int>>dp(n, vector<int>(n,0));
        unordered_map<int,int>mp;
        for(int i = 0; i<n; i++){
            int num = arr[i];
            mp[num] = i;
            for(int prev = 0; prev<n; prev++){
                int diff = arr[i]-arr[prev];
                int idx = mp.count(diff) ? mp[diff] : -1;
                if(diff < arr[prev] && idx>=0){
                    dp[prev][i] = 1+dp[idx][prev];
                }
                else dp[prev][i] = 2;
                ans = max(ans, dp[prev][i]);
            }
        }
        return ans>=3 ? ans : 0;
    }
};

// int lenLongestFibSubseq(vector<int>& arr) {
//         int n = arr.size();
//         set<int>st;
//         for(int num : arr) st.insert(num);
//         int cnt = 2, ans = 0;
//         for(int i = 0; i<n; i++){
//             for(int j = i+1; j<n; j++){
//                 int a = arr[i], b = arr[j];
//                 cnt = 2;
//                 while(st.count(a+b)){
//                     int temp = a+b;
//                     a = b;
//                     b = temp;
//                     cnt++;
//                 }
//                 ans = max(ans, cnt);
//             }
//         }
//         return ans>=3 ? ans : 0;
//     }
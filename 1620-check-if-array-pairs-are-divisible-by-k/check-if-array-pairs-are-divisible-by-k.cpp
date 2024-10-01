class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int>cnt(k,0);
        for(int i = 0; i<n; i++){
            int rem = ((arr[i]%k)+k)%k;
            cnt[rem]++;
        }
        if(cnt[0] & 1) return 0;
        for(int i = 1; i<=k/2; i++){
            if(cnt[i] != cnt[k-i]) return 0;
        }
        return 1;
    }
};

// class Solution {
// public:
//     bool canArrange(vector<int>& arr, int k) {
//         int n = arr.size(), cnt = 0;
//         vector<bool>used(n,0);
//         for(int i = 0; i<n; i++){
//             if(used[i]) continue;
//             bool f = 0;
//             for(int j = i+1; j<n; j++){
//                 if(!used[j] && (arr[i]+arr[j])%k == 0){
//                     used[i] = 1;
//                     used[j] = 1;
//                     f = 1;
//                     cnt++;
//                     break;
//                 }
//             }
//             if(!f) return 0;
//         }
//         return cnt == n/2;
//     }
// };
class Solution {
    public int minimumRecolors(String blocks, int k) {
        int n = blocks.length();
        int l = 0, cnt = 0, ans = Integer.MAX_VALUE;
        for(int r = 0; r<n; r++){
            if(blocks.charAt(r) == 'B') cnt++;
            while(r-l+1>k){
                if(blocks.charAt(l) == 'B') cnt--;
                l++;
            }
            ans = Math.min(ans, k-cnt);
        }
        return ans<0 ? 0 : ans;
    }
}

// class Solution {
// public:
//     int minimumRecolors(string blocks, int k) {
//         int n = blocks.size(), l = 0, ans = INT_MAX, cnt = 0;
//         for(int r = 0; r<n; r++){
//             if(blocks[r] == 'B') cnt++;
//             while(r-l+1>k){
//                 if(blocks[l] == 'B') cnt--;
//                 l++;
//             }
//             ans = min(ans, k-cnt);
//         }
//         return ans<0 ? 0 : ans;
//     }
// };
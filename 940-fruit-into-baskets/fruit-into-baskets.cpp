class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        unordered_map<int,int>mp;
        int l = 0, r = 0, ans = 0;
        while(r<n){
            mp[fruits[r]]++;
            while(mp.size()>2){
                mp[fruits[l]]--;
                if(mp[fruits[l]] == 0) mp.erase(fruits[l]);
                l++;
            }
            ans = max(ans, r-l+1);
            r++;
        }
        return ans;
    }
};

// class Solution {
// public:
//     int totalFruit(vector<int>& fruits) {
//         int n = fruits.size();
//         int ans = INT_MIN;
//         for(int i = 0; i<n; i++){
//             unordered_set<int>st;
//             int cnt = 0;
//             for(int j = i; j<n; j++){
//                 st.insert(fruits[j]);
//                 if(st.size()>2) break;
//                 cnt++;
//             }
//             ans = max(ans,cnt);
//         }
//         return ans;
//     }
// };
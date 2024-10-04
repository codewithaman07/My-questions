class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();
        int n2 = n/2;
        vector<int>cnt(1001,0);
        int sum = 0;
        long long ans = 0;
        for(int i = 0; i<n; i++){
            sum+=skill[i];
            cnt[skill[i]]++;
        }
        if(sum%n2 != 0) return -1;
        int x = sum/n2;
        for(int i = 0; i<n; i++){
            int a = skill[i];
            int b = x-a;
            if(cnt[b]<=0) return -1;
            ans+=(a*b);
            cnt[b]--;
        }
        return ans/2;
    }
};

// class Solution {
// public:
//     long long dividePlayers(vector<int>& skill) {
//         sort(skill.begin(), skill.end());
//         int n = skill.size(), sum = skill[0]+skill[n-1];
//         int l = 0, r = n-1;
//         long long ans = 0;
//         while(l<r){
//             if(sum == skill[l]+skill[r]){
//                 ans+=(skill[l]*skill[r]);
//                 l++; r--;
//             }
//             else return -1;
//         }
//         return ans;
//     }
// };
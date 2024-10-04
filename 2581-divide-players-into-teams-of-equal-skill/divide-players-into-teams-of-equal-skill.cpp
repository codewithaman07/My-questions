class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(), skill.end());
        int n = skill.size(), sum = skill[0]+skill[n-1];
        int l = 0, r = n-1;
        long long ans = 0;
        while(l<r){
            if(sum == skill[l]+skill[r]){
                ans+=(skill[l]*skill[r]);
                l++; r--;
            }
            else return -1;
        }
        return ans;
    }
};
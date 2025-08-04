class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size(), l = 0, ans = 0;
        unordered_map<int,int>mp;
        for(int r = 0; r<n; r++){
            mp[fruits[r]]++;
            while(mp.size()>2){
                if(--mp[fruits[l]] == 0) mp.erase(fruits[l]);
                l++;
            }
            ans = max(ans, r-l+1);
        }
        return ans;
    }
};
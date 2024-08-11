class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int k = 2, l = 0, r = 0, n = fruits.size(), len = 0, maxi = 0;
        map<int,int>mp;
        while(r<n){
            mp[fruits[r]]++;
            if(mp.size()>k){
                mp[fruits[l]]--;
                if(mp[fruits[l]] == 0) mp.erase(fruits[l]);
                l++;
            }
            if(mp.size()<=k){
                len = r-l+1;
                maxi = max(maxi,len);
            }
            r++;
        }
        return maxi;
    }
};
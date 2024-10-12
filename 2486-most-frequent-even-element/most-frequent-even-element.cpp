class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        map<int,int>mp;
        int ans = -1, maxi = -1;
        for(int num : nums){
            if((num&1) == 0) mp[num]++;
            if(mp[num] == maxi){
                ans = min(ans,num);
            }
            else{
                if(mp[num] > maxi){
                    maxi = mp[num];
                    ans = num;
                }
            }
        }
        return (ans&1) ? -1 : ans;
    }
};
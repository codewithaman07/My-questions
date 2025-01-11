class Solution {
public:
    #define ll long long
    long long maximumCoins(vector<vector<int>>& coins, int k) {
        int n = coins.size();
        sort(coins.begin(),coins.end());
        ll ans = INT_MIN, sum = 0;
        for(int i = 0, j = 0; i<n; i++){
            while(j<n && coins[j][1] <= coins[i][0]+k-1){
                sum+=1ll*(coins[j][1] - coins[j][0] +1)*coins[j][2];
                j++;
            }
            if(j<n){
                ll part = 1ll*(coins[i][0]+k-1 - coins[j][0]+1)*coins[j][2];
                part = max(0ll, part);
                ans = max(ans, sum+part);
            }
            sum-= 1ll*(coins[i][1]-coins[i][0]+1)*coins[i][2];
        }
        sum = 0;
        for(int i = 0, j = 0; i<n; i++){
            sum+= 1ll*(coins[i][1]-coins[i][0]+1)*coins[i][2];
            while(coins[j][1] < coins[i][1]-k+1){
                sum-= 1ll*(coins[j][1]-coins[j][0]+1)*coins[j][2];
                j++;
            }
            ll part = 1ll*(coins[i][1]-k - coins[j][0] + 1)*coins[j][2];
            part = max(0ll, part);
            ans = max(ans, sum-part);
        }
        return ans;
    }
};
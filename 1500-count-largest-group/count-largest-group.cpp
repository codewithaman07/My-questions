class Solution {
public:
    int fun(int num){
        int sum = 0;
        while(num){
            sum+=(num%10);
            num/=10;
        }
        return sum;
    }
    int countLargestGroup(int n) {
        unordered_map<int,int>mp;
        int maxi = 0;
        for(int i = 1; i<=n; i++){
            int num = fun(i);
            mp[num]++;
            maxi = max(maxi, mp[num]);
        }
        int cnt = 0;
        for(auto &[x, y] : mp){
            if(maxi == y) cnt++;
        }
        return cnt;
    }
};
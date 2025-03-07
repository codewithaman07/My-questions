class Solution {
public:
    vector<int>seive(int n){
        vector<int>primes(n+1, 1);
        primes[0] = 0, primes[1] = 0;
        for(int i = 2; i*i<=n; i++){
            if(primes[i]){
                for(int j = i*i; j<=n; j+=i){
                    primes[j] = 0;
                }
            }
        }
        return primes;
    }
    vector<int> closestPrimes(int l, int r) {
        vector<int>prime = seive(r);
        vector<int>primes;
        for(int i = l; i<=r; i++){
            if(prime[i]) primes.push_back(i);
        }
        vector<int>ans(2,-1);
        int mini = INT_MAX;
        for(int i = 1; i<primes.size(); i++){
            int diff = primes[i]-primes[i-1];
            if(diff < mini){
                mini = diff;
                ans[0] = primes[i-1];
                ans[1] = primes[i];
            }
        }
        for(int num : primes) cout<<num<<" ";
        return ans;
    }
};
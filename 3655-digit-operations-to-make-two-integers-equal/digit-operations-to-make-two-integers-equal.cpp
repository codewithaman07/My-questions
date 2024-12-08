class Solution {
public:
    const int maxi = 1e5;
    vector<bool> primes;
    Solution() : primes(maxi, true) {}
    void sieve() {
        primes[0] = 0;
        primes[1] = 0;
        for (int i = 2; i * i < maxi; i++) {
            if (primes[i]) {
                for (int j = i * i; j < maxi; j += i) {
                    primes[j] = 0;
                }
            }
        }
    }
    vector<int>fun(int n){
        vector<int>res;
        for(int i = 1; i<=n; i*=10){
            int d = (n/i)%10;
            if(d>0) res.push_back(n-i);
            if(d<9) res.push_back(n+i);
        }
        return res;
    }
    int minOperations(int n, int m) {
        sieve();
        if(primes[n] || primes[m]) return -1;
        vector<int>dist(1e4, INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        dist[n] = 0;
        pq.push({dist[n], n});
        while(!pq.empty()){
            int u,d;
            tie(d,u) = pq.top();
            pq.pop();
            if(d != dist[u]) continue;
            for(int v : fun(u)){
                if(primes[v]) continue;
                if(dist[v] >dist[u]+u){
                    dist[v] = dist[u]+u;
                    pq.push({dist[v],v});
                }
            }
        }
        if(dist[m] == INT_MAX) return -1;
        return m+dist[m];
    }
};
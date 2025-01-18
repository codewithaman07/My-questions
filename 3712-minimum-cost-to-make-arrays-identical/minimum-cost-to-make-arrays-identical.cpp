class Solution {
public:
    #define ll long long
    long long minCost(vector<int>& arr, vector<int>& brr, long long k) {
        ll x = 0, y = 0;
        vector<int>a(arr.begin(), arr.end());
        vector<int>b(brr.begin(), brr.end());
        int n = arr.size();
        sort(arr.begin(), arr.end());
        sort(brr.begin(),brr.end());
        for(int i = 0; i<n; i++){
            x+= abs(brr[i]-arr[i]);
            y+= abs(b[i]-a[i]);
        }
        return min(x+k, y);
    }
};
class Solution {
public:
    bool check(vector<int>&arr, int k, int mid){
        int n = arr.size();
        int cnt = 1, prev = arr[0];
        for(int i = 1; i<n; i++){
            if(arr[i]-prev < mid) continue;
            cnt++;
            prev = arr[i]; 
        }
        return cnt>=k;
    }
    int maximumTastiness(vector<int>& arr, int k) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int l = 0, r = arr[n-1]-arr[0], ans = 0;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(check(arr,k,mid)){
                ans = mid;
                l = mid+1;
            }
            else r = mid-1;
        }
        return ans;
    }
};
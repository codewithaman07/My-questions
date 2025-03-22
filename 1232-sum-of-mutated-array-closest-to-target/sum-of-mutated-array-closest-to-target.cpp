class Solution {
public:
    int fun(int m, vector<int>&arr, int t){
        int n = arr.size(), sum = 0;
        for(int i = 0; i<n; i++){
            sum+=min(m,arr[i]);
        }
        return abs(sum-t);
    }
    int findBestValue(vector<int>& arr, int target) {
        int n = arr.size(), l = 0, r = target, ans = 0;
        while(l<r){
            int m = l+(r-l)/2;
            if(fun(m,arr,target)<=fun(m+1,arr,target)){
                r = m;
                ans = m;
            }
            else l = m+1;
        }
        return ans;
    }
};
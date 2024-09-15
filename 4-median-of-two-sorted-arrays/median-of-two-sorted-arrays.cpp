class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums, vector<int>& arr) {
        int n = nums.size(), m = arr.size(), idx = 0;
        vector<int>v(n+m);
        int i = 0, j = 0;
        while(i<n && j<m){
            if(nums[i]<arr[j]) v[idx++] = nums[i++];
            else v[idx++] = arr[j++];
        }
        while(i<n) v[idx++] = nums[i++];
        while(j<m) v[idx++] = arr[j++];
        n = n+m;
        for(int i = 0; i<n; i++) cout<<v[i]<<" ";
        if(n&1) return v[n/2]*1.0;
        else return (v[n/2-1]+v[n/2])/2.0;
    }
};
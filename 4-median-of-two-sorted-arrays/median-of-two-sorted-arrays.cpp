class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums, vector<int>& arr) {
        int n = nums.size(), m = arr.size(), idx = 0;
        vector<double>v(n+m);
        for(int i = 0; i<n; i++) v[idx++] = nums[i];
        for(int i = 0; i<m; i++) v[idx++] = arr[i];
        sort(v.begin(), v.end());
        n = n+m;
        if(n&1) return v[n/2]*1.0;
        else return (v[n/2-1]+v[n/2])/2.0;
    }
};
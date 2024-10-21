class Solution {
public:
    #define ll long long
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        ll z1 = 0, z2 = 0, sum1 = 0, sum2 = 0;
        for(int i = 0; i<n; i++){
            if(nums1[i] == 0) z1++;
            sum1+=nums1[i];
        }
        for(int i = 0; i<m; i++){
            if(nums2[i] == 0) z2++;
            sum2+=nums2[i];
        }
        if(z1 == 0 && sum1<sum2+z2 || z2 == 0 && sum2<sum1+z1) return -1;
        return max(sum1+z1, sum2+z2);
    }
};
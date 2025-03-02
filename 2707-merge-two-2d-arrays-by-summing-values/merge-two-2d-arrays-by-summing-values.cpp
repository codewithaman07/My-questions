class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        vector<vector<int>>nums;
        int n = nums1.size(), m = nums2.size();
        int i = 0, j = 0;
        while(i<n && j<m){
            if(nums1[i][0]<nums2[j][0]){
                nums.push_back({nums1[i][0], nums1[i][1]});
                i++;
            }
            else if(nums1[i][0] == nums2[j][0]){
                nums.push_back({nums1[i][0], nums1[i][1]+nums2[j][1]});
                i++;
                j++;
            }
            else{
                nums.push_back({nums2[j][0], nums2[j][1]});
                j++;
            }
        }
        while(i<n){
            nums.push_back({nums1[i][0], nums1[i][1]});
            i++;
        }
        while(j<m){
            nums.push_back({nums2[j][0], nums2[j][1]});
            j++;
        }
        return nums;
    }
};
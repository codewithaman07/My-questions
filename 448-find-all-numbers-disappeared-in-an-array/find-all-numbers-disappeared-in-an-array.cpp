class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int>arr(n+1,1);
        vector<int>ans;
        for(int i = 0; i<n; i++){
            arr[nums[i]] = 0;
        }
        for(int i = 1; i<=n; i++) if(arr[i]) ans.push_back(i);
        return ans;
    }
};
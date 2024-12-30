class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        set<float>st;
        sort(nums.begin(), nums.end());
        int l = 0, r = nums.size()-1;
        while(l<r){
            auto temp = (nums[l]+nums[r])/2.0;
            st.insert(temp);
            l++, r--;
        }
        return st.size();
    }
};
class Solution {
public:
    vector<int> maxKDistinct(vector<int>& nums, int k) {
        set<int>st;
        for(int num : nums) st.insert(num);
        vector<int>temp, ans;
        for(int num : st) temp.push_back(num);
        for(int i = temp.size()-1; i>=0; i--){
            if(ans.size() > k-1) break;
            ans.push_back(temp[i]);
        }
        return ans;
    }
};
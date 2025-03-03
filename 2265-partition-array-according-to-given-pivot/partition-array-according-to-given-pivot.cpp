class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int>ans;
        for(int &num : nums){
            if(num<pivot && num != INT_MIN){
                ans.push_back(num);
                num = INT_MIN;
            }
        }
        for(int &num : nums){
            if(num == pivot && num != INT_MIN){
                ans.push_back(num);
                num = INT_MIN;
            }
        }
        for(int &num : nums){
            if(num>pivot && num != INT_MIN){
                ans.push_back(num);
                num = INT_MIN;
            }
        }
        return ans;
    }
};
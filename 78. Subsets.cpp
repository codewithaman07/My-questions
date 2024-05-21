class Solution {
public:
    // Recursive function to generate subsets
    void solve(int i, vector<int> &nums, vector<int> &temp, vector<vector<int>> &result) {
        int n = nums.size();
        
        // Base case: if we have considered all elements
        if (i == n) {
            result.push_back(temp);  // Add the current subset to the result
            return;
        }
        
        // Include the current element in the subset
        temp.push_back(nums[i]);
        solve(i + 1, nums, temp, result);  // Recurse with the next index
        
        // Exclude the current element from the subset
        temp.pop_back();
        solve(i + 1, nums, temp, result);  // Recurse with the next index
    }
    
    // Function to generate all subsets of the given vector 'nums'
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;  // Temporary vector to store current subset
        vector<vector<int>> result;  // Vector to store all subsets
        
        // Start the recursive process from index 0
        solve(0, nums, temp, result);
        
        return result;  // Return the result containing all subsets
    }
};

class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == k) return *max_element(nums.begin(), nums.end());
        if(k == 1){
            unordered_map<int,int>mp;
            for(int i = 0; i<n; i++){
                mp[nums[i]]++;
            }
            int maxi = -1;
            for(auto &[x,y] : mp){
                if(y == 1) maxi = max(maxi,x);
            }
            return maxi;
        }
        int l = 0, r = nums.size()-1;
        int x = 1, y = 1;
        if(nums[l] == nums[r]) return -1;
        for(int i = 1; i<n-1; i++){
            if(nums[i] == nums[l]) x = 0;
            if(nums[i] == nums[r]) y = 0;
        }
        cout<<"x: "<<x<<"y : "<<y<<endl;
        if(x == 0 && y == 0) return -1;
        if(x == 1 && y == 1) return max(nums[l], nums[r]);
        if(x) return nums[l];
        if(y) return nums[r];
        return max(nums[l], nums[r]);
    }
};
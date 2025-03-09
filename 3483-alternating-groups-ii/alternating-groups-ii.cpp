class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& nums, int k) {
        int n = nums.size(), cnt = 0, l = 0;
        vector<int>arr(nums.begin(), nums.end());
        for(int i = 0; i<n-1; i++) arr.push_back(nums[i]);
        unordered_map<int,int>mp;
        int prev = -1;
        for(int r = 0; r<arr.size(); r++){
            if(prev == arr[r]) l = r;
            prev = arr[r]; 
            while(r-l+1>=k){
                if(!mp.count((r%n)+1)) cnt++, l++;
                else l = r;
                mp[(r%n)+1]++;
            }
        }
        return cnt;
    }
};
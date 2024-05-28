class Solution {
public:
    int specialArray(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int curr = 1;
        int s = 1, e=nums.size(), m=s+(e-s)/2;
        while(s<=e){
            int cnt = 0;
            for(int j=0; j<nums.size(); j++){
                if(nums[j]>=m) cnt++;
            }
            if(cnt==m) return m;
            if(cnt>m) s = m+1;
            else e = m-1;
            m = s+(e-s)/2;
        }
        return -1;
    }
};

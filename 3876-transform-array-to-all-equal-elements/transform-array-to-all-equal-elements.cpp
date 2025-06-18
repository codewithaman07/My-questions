class Solution {
public:
    bool canMakeEqual(vector<int>& nums, int k) {
        int n = nums.size(), x = 0, y = 0;
        vector<int>temp = nums;
        for(int i = 0; i<n-1; i++){
            if(temp[i] == -1){
                x++;
                temp[i]*=(-1);
                temp[i+1]*=(-1);
            }
            if(i == n-2 && temp[n-1] == -1) x = k+1;
        }
        temp = nums;
        for(int i = 0; i<n-1; i++){
            if(temp[i] == 1){
                y++;
                temp[i]*=(-1);
                temp[i+1]*=(-1);
            }
            if(i == n-2 && temp[n-1] == 1) y = k+1;
        }
        return min(x,y) > k ? 0 : 1;
    }
};
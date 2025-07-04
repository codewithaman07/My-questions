class Solution {
public:
    #define ll long long
    char kthCharacter(long long k, vector<int>& nums) {
        if(k == 1) return 'a';
        ll len = 1, n = nums.size(), newK = -1;
        int op = -1;
        for(int i = 0; i<n; i++){
            len*=2;
            if(len>=k){
                newK = k-len/2;
                op = nums[i];
                break;
            }
        }
        char ch = kthCharacter(newK, nums);
        if(!op) return ch;
        return ch == 'z' ? 'a' : ch+1;
    }
};
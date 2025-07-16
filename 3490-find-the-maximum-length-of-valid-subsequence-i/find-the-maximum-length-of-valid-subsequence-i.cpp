class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int e = 0, o = 0, cnt = 0, f = -1;
        for(auto i : nums){
            if(i&1){
                o++;
                if(f!=1){
                    cnt++;
                    f = 1;
                }
            }
            else{
                e++;
                if(f!=0){
                    cnt++;
                    f = 0;
                }
            }
        }
        return max({o,e,cnt});
    }
};
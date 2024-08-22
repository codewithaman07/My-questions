class Solution {
public:
    int findComplement(int num) {
        int ans = 0, i = 0;
        while(num){
            int temp = num&1;
            if(!temp) ans+=(1<<i);
            i++;
            num = num>>1;
        }
        return ans;
    }
};
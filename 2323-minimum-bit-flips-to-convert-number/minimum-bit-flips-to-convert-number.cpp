class Solution {
public:
    int minBitFlips(int start, int goal) {
        int x = start^goal; // taking xor so get different bits in both numbers
        int cnt = 0;
        while(x){
            if(x&1){ // bits are different that's why we get one by tsking xor 1&1 = 1;
                cnt++; 
                x>>=1;
            }
            else x>>=1;
        }
        return cnt;
    }
};
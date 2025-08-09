class Solution {
public:
    bool isPowerOfTwo(int n) {
        int num = __builtin_popcount(n);
        return n>0 && num == 1;
    }
};
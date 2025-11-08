class Solution {
public:
    int passThePillow(int n, int k) {
        n--;
        int num = k/n;
        int rem = k%n;
        if(num&1) return n-rem+1;
        else return rem+1;
    }
};
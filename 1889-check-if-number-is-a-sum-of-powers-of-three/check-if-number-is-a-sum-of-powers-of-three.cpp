class Solution {
public:
    bool checkPowersOfThree(int n) {
        while(n>0){
            int rem = n%3;
            if(rem == 2) return 0;
            n/=3;
        }
        return 1;
    }
};
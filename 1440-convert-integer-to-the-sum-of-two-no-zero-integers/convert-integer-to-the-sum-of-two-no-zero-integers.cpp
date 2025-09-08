class Solution {
public:
    bool isValid(int num){
        while(num > 0){
            if(num%10 == 0) return false;
            num/=10;
        }
        return true;
    }
    vector<int> getNoZeroIntegers(int n) {
        for(int num = 1; num <= n/2; num++){
            if(isValid(num) && isValid(n-num)) return {num, n-num};
        }
        return {};
    }
};
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int f = 0, flag = 0;
        for(int i = n-1; i>=0; i--){
            int num = digits[i];
            if(f || i == n-1){
                if(num+1>=10){
                    if(i == 0) flag = 1;
                    f = 1;
                    digits[i] = 0;
                }
                else{
                    digits[i] = num+1;
                    f = 0;
                }
            }
        }
        if(!flag) return digits;
        digits.insert(digits.begin(), 1);
        return digits;
    }
};
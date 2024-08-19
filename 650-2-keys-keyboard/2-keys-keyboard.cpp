class Solution {
public:
    int minSteps(int n) {
        int ans = 0, fact = 2;
        while(n>1){
            while(n%fact == 0){
                ans+=fact;
                n/=fact;
            }
            fact++;
        }
        return ans;
    }
};
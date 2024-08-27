class Solution {
public:
    int solve(int n){
        int ans = 0;
        while(n){
            int a = n%10;
            ans+=(a*a);
            n/=10;
        }
        return ans;
    }
    bool isHappy(int n) {
        set<int>st;
        while(st.find(n) == st.end()){
            if(n == 1) return 1;
            st.insert(n);
            n = solve(n);
        }
        return 0;
    }
};
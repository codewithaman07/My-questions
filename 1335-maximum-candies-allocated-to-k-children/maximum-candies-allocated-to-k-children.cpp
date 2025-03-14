class Solution {
public:
    #define ll long long
    bool fun(vector<int>&nums, int &n, ll m, ll k){
        if(m == 0) return 1;
        ll cnt = 0;
        for(int i = 0; i<n; i++){
            cnt+=(nums[i]/m);
            if(cnt>=k) return 1;
        }
        return cnt>=k;
    }
    int maximumCandies(vector<int>& nums, long long k) {
        int n = nums.size();
        ll l = 0, r = accumulate(nums.begin(), nums.end(), 0ll)/k, ans = 0;
        while(l<=r){
            ll m = l+(r-l)/2;
            cout<<"m is :"<<m<<endl;
            if(fun(nums, n, m, k)){
                l = m+1;
                ans = m;
                cout<<"i am in if"<<endl;
            }
            else{
                r = m-1;
                cout<<"i am in else"<<endl;
            }
        }
        return ans;
    }
};
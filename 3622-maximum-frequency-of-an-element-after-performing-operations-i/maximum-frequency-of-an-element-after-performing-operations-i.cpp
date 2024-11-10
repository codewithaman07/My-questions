class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int op) {
        int n = nums.size(), ans = 1, sum = 0;
        map<int,int>mp, freq;
        set<int>st;
        for(int &num : nums){
            freq[num]++;
            st.insert(num);
            st.insert(num-k);
            st.insert(num+k+1);
            mp[num-k]++;
            mp[num+k+1]--;
        }
        for(auto &num : st){
            sum+=mp[num];
            ans = max(ans, freq[num]+min(op, sum-freq[num]));
        }
        return ans;
    }
};
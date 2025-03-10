class Solution {
public:
    #define ll long long 
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        ll sum = 0;
        vector<ll>ans(n,0);
        priority_queue<ll, vector<ll>, greater<ll>>pq;
        vector<pair<int,int>>arr;
        for(int i = 0; i<n; i++) arr.push_back({nums1[i], i});
        sort(arr.begin(),arr.end());
        int i = 0;
        while(i<n){
            int j = i;
            while(j<n && arr[i].first == arr[j].first) j++;
            for(int p = i; p<j; p++) ans[arr[p].second] = sum;
            for(int p = i; p<j; p++){
                int idx = arr[p].second;
                pq.push(nums2[idx]);
                sum+=nums2[idx];
                if(pq.size()>k) sum-=pq.top(), pq.pop();
            }
            i = j;
        }
        return ans;
    }
};
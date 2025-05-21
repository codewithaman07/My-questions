class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int ans = 0, n = nums.size();
        vector<pair<int,int>>arr;
        for(int i = 0; i<n; i++){
            string temp = to_string(nums[i]);
            int sum = 0;
            for(auto x : temp){
                sum+=(x-'0');
            }
            arr.push_back({sum,nums[i]});
        }
        sort(arr.begin(),arr.end());
        unordered_map<int,vector<int>>mp;
        for(int i = 0; i<n; i++){
            mp[nums[i]].push_back(i);
        }
        for(int i = 0; i<n; i++){
            int num = arr[i].second;
            mp[num].push_back(i);
        }
        vector<int>to(n,-1);
        for(auto [x,y] : mp){
            to[y[0]] = y[1];
        }
        vector<bool>seen(n,0);
        for(int i = 0; i<n; i++){
            if(seen[i] || to[i] == i) continue;
            int j = i, cnt = 0;
            while(!seen[j]){
                seen[j] = 1;
                j = to[j];
                cnt++;
            }
            ans+=(cnt-1);
        }
        return ans;
    }
};

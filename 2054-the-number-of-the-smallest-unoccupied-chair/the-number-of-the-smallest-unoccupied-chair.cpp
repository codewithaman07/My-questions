class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();
        auto x = times[targetFriend];
        sort(times.begin(), times.end());
        vector<int>arr(n);
        for(auto it : times){
            for(int i = 0; i<n; i++){
                if(arr[i]<=it[0]){
                    arr[i] = it[1];
                    if(it == x) return i;
                    break;
                }
            }
        }
        return 0;
    }
};
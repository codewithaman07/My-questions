class Solution {
public:
    bool fun(string &x, string &y){
        if(x == y) return 1;
        int n = x.size();
        string sx = x, sy = y;
        for(int i = 0; i<n; i++){
            for(int j = i+1; j<n; j++){
                swap(sx[i], sx[j]);
                if(stoi(sx) == stoi(y)) return 1;
                swap(sx[i], sx[j]);
            }
        }
        for(int i = 0; i<n; i++){
            for(int j = i+1; j<n; j++){
                swap(sy[i], sy[j]);
                if(stoi(sy) == stoi(x)) return 1;
                swap(sy[i], sy[j]);
            }
        }
        return 0;
    }

    int countPairs(vector<int>& nums) {
        int n = nums.size(), maxi = 0;
        vector<string>temp(n);
        for(int i = 0; i<n; i++){
            string s = to_string(nums[i]);
            maxi = max(maxi, (int)s.size());
        }
        for(int i = 0; i<n; i++){
            string s = to_string(nums[i]);
            int x = s.size();
            if(x < maxi){
                s = string(maxi-x, '0')+s;
            }
            temp[i] = s;
        }
        unordered_map<string,vector<string>>mp;
        for(int i = 0; i<n; i++){
            string key = temp[i];
            sort(key.begin(),key.end());
            mp[key].push_back(temp[i]);
        }
        int ans = 0;
        for(auto &[str, arr] : mp){
            int n = arr.size();
            for(int i = 0; i<n; i++){
                for(int j = i+1; j<n; j++){
                    if(fun(arr[i], arr[j])) ans++;
                }
            }
        }
        return ans;
    }
};
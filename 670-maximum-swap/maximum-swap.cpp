class Solution {
public:
    int maximumSwap(int num) {
        string temp = to_string(num);
        int maxi = INT_MIN, n = temp.size(), ans = num;
        for(int i = 0; i<n; i++){
            for(int j = i+1; j<n; j++){
                swap(temp[i],temp[j]);
                ans = max(ans, stoi(temp));
                swap(temp[i], temp[j]);
            }
        }
        return ans;
    }
};
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size(), sum = 0, temp = 0, ans = 0;
        for(int i = 0; i<n; i++){
            sum+=arr[i];
            temp+=i;
            if(sum == temp) ans++;
        }
        return ans;
    }
};
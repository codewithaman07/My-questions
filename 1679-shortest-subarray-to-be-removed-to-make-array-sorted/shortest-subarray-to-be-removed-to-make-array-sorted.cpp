class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size(), i = 0;
        int j = n-1;
        while(j>0 && arr[j-1] <= arr[j]) j--;
        int ans = j;
        while(i<j && (i == 0 || arr[i-1]<=arr[i])){
            while(j<n && arr[i] > arr[j]) j++;
            ans = min(ans, j-i-1);
            i++;
        }
        return ans;
    }
};
class Solution {
public:
    int findLucky(vector<int>& arr) {
        vector<int>freq(501,0);
        int n = arr.size();
        for(int i = 0; i<n; i++){
            freq[arr[i]]++;
        }
        int ans = -1, maxi = -1;
        for(int i = 0; i<freq.size(); i++){
            if(freq[i]>0 && freq[i]>maxi && freq[i] == i){
                ans = i;
                maxi = freq[i];
            }
        }
        return ans;
    }
};
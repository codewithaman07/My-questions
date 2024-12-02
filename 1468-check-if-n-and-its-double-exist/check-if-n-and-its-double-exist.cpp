class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(),arr.end());
        int num = 0;
        for(int i = 0; i<n; i++) if(arr[i] == 0) num++;
        for(int i = 0; i<n; i++){
            if(binary_search(arr.begin(), arr.end(), 2*arr[i])){
                if(arr[i] != 0) return 1;
                if(arr[i] == 0 && num >=2) return 1;
            }
        }
        return 0;
    }
};
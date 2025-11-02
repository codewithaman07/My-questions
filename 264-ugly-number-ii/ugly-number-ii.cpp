class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int>arr;
        arr.push_back(1);
        int x = 0, y = 0, z = 0;
        for(int i = 1; i<n; i++){
            int num = min({arr[x]*2, arr[y]*3, arr[z]*5});
            arr.push_back(num);
            if(num == arr[x]*2) x++;
            if(num == arr[y]*3) y++;
            if(num == arr[z]*5) z++; 
        }
        return arr.back();
    }
};
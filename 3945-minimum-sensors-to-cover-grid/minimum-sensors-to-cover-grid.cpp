class Solution {
public:
    int minSensors(int n, int m, int k) {
        int num = 2*k+1;
        return ((n+num-1)/num)*((m+num-1)/num);
    }
};
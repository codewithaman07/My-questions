class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int tgas = accumulate(gas.begin(), gas.end(),0);
        int tcost = accumulate(cost.begin(), cost.end(), 0);
        if(tcost>tgas) return -1;
        int ans = 0, idx = 0;
        for(int i = 0; i<n; i++){
            ans+=(gas[i]-cost[i]);
            if(ans<0) {
                ans = 0;
                idx = i+1;
            } 
        }
        return idx;
    }
};

// int n = gas.size();
//         for(int i = 0; i < n; i++){
//             if(gas[i] < cost[i]) continue;
//             int j = (i + 1) % n;
//             int curr = gas[i] - cost[i];
//             while(j != i){
//                 curr += gas[j] - cost[j];
//                 if(curr < 0) break;
//                 j = (j + 1) % n;
//             }
//             if(j == i) return i;
//         }
//         return -1;
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        int l = 0, r = n-1;
        while(r-l>=k){
            if(abs(arr[l]-x) <= abs(arr[r]-x)) r--;
            else l++;
        }
        vector<int>ans(arr.begin()+l, arr.begin()+l+k);
        return ans;
    }
};

// class Solution {
// public:
//     vector<int> findClosestElements(vector<int>& arr, int k, int x) {
//         priority_queue<int, vector<int>, greater<int>>pq;
//         int n = arr.size();
//         for(int i = 0; i<k; i++){
//             pq.push(arr[i]);
//         }
//         for(int i = k; i<n; i++){
//             int curr = pq.top();
//             if(abs(curr-x)> abs(arr[i]-x)){
//                 pq.pop();
//                 pq.push([i]);
//             }
//         }
//         vector<int>ans;
//         while(!pq.empty()){
//             ans.push_back(pq.top());
//             pq.pop();
//         }
//         return ans;
//     }
// }; TC nearly O(nlogk)
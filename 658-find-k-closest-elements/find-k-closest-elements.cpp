class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<int, vector<int>, greater<int>>pq;
        int n = arr.size();
        for(int i = 0; i<k; i++){
            pq.push(arr[i]);
        }
        for(int i = k; i<n; i++){
            int curr = pq.top();
            if(abs(curr-x)> abs(arr[i]-x)){
                pq.pop();
                pq.push(arr[i]);
            }
        }
        vector<int>ans;
        while(!pq.empty()){
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
    }
};
class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        set<int>st;
        for(int num : arr) st.insert(num);
        int cnt = 2, ans = 0;
        for(int i = 0; i<n; i++){
            for(int j = i+1; j<n; j++){
                int a = arr[i], b = arr[j];
                cnt = 2;
                while(st.count(a+b)){
                    int temp = a+b;
                    a = b;
                    b = temp;
                    cnt++;
                }
                ans = max(ans, cnt);
            }
        }
        return ans>=3 ? ans : 0;
    }
};
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size(), cnt = 0;
        vector<int>ans(n,0);
        set<int>st1,st2;
        for(int i = 0; i<n; i++){
            st1.insert(A[i]);
            st2.insert(B[i]);
            for(int num : st1){
                if(st2.count(num)) cnt++;
            }
            ans[i] = cnt;
            cnt = 0;
        }
        return ans;
    }
};
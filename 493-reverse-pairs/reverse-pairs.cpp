class Solution {
public:
    int cnt = 0;
    int solve(vector<int>&a, vector<int>&b){
        int c = 0, n = a.size(), m = b.size();
        int i = 0, j = 0;
        while(i<n && j<m){
            long long int temp = b[j];
            if(a[i]> 2*temp){
                cnt+= n-i;
                j++;
            }
            else i++;
        }
        return c;
    }
    void merge(vector<int>&a, vector<int>&b, vector<int>&res){
        int i = 0, j = 0, k = 0, n = a.size(), m = b.size();
        while(i<n && j<m){
            if(a[i]<=b[j]) res[k++] = a[i++];
            else res[k++] = b[j++];
        }
        if(i == n) while(j<m) res[k++] = b[j++];
        else if(j == m) while(i<n) res[k++] = a[i++];
    }
    void mergeSort(vector<int>&arr){
        int n = arr.size();
        if(n == 1) return;
        int n1 = n/2, n2 = n-n/2;
        vector<int>a(n1), b(n2);
        for(int i = 0; i<n1; i++) a[i] = arr[i];
        for(int i = 0; i<n2; i++) b[i] = arr[i+n1];
        mergeSort(a); mergeSort(b);
        cnt+= solve(a,b);
        merge(a,b,arr);
        // a.clear(); b.clear();
    }

    int reversePairs(vector<int>& nums) {
        mergeSort(nums);
        return cnt;
    }
};
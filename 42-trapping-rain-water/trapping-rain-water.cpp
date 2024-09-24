class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        int n = height.size();
        vector<int>pre(n), suf(n);
        pre[0] = height[0];
        suf[n-1] = height[n-1];
        for(int i = 1; i<n; i++){
            pre[i] = max(pre[i-1], height[i]);
        }
        for(int i = n-2; i>=0; i--){
            suf[i] = max(suf[i+1], height[i]);
        }
        for(int i = 0; i<n; i++){
            ans+= (min(pre[i], suf[i])-height[i]);
        }
        return ans;
    }
};


    // int trap(vector<int>& height) {
    //     int n = height.size();
    //     int ans = 0;
    //     for(int i = 0; i<n; i++){
    //         int left = 0, right = 0;
    //         for(int j = i; j<n; j++){
    //             right = max(right,height[j]);
    //         }
    //         for(int j = 0; j<=i; j++){
    //             left = max(left, height[j]);
    //         }
    //         ans+= (min(left,right)-height[i]);
    //     }
    //     return ans;
    // }

    // int trap(vector<int>& height) {
    //     int size = height.size();
    //     int leftIdx = 0, rightIdx = size-1;
    //     int leftMaxHeight = 0, rightMaxHeight = 0;
    //     int ans = 0;
    //     while(leftIdx < rightIdx){
    //         leftMaxHeight = max(leftMaxHeight, height[leftIdx]);
    //         rightMaxHeight = max(rightMaxHeight, height[rightIdx]);
    //         if(leftMaxHeight < rightMaxHeight){
    //             ans+=(leftMaxHeight-height[leftIdx]);
    //             leftIdx++;
    //         }
    //         else{
    //             ans+=(rightMaxHeight-height[rightIdx]);
    //             rightIdx--;
    //         }
    //     }
    //     return ans;
    // }
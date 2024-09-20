class Solution {
public:
    int trap(vector<int>& height) {
        int size = height.size();
        int leftIdx = 0, rightIdx = size-1;
        int leftMaxHeight = 0, rightMaxHeight = 0;
        int ans = 0;
        while(leftIdx < rightIdx){
            leftMaxHeight = max(leftMaxHeight, height[leftIdx]);
            rightMaxHeight = max(rightMaxHeight, height[rightIdx]);
            if(leftMaxHeight < rightMaxHeight){
                ans+=(leftMaxHeight-height[leftIdx]);
                leftIdx++;
            }
            else{
                ans+=(rightMaxHeight-height[rightIdx]);
                rightIdx--;
            }
        }
        return ans;
    }
};
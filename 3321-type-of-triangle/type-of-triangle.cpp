class Solution {
public:
    string triangleType(vector<int>& nums) {
        int a = nums[0], b = nums[1], c = nums[2];
        if(a+b<=c || b+c<=a || c+a<=b) return "none";
        else if(a == b && b == c && c == a) return "equilateral";
        else if(a != b && b != c && c != a) return "scalene";
        else return "isosceles";
    }
};
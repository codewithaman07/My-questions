class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        vector<int>temp;
        for(int &num : nums){
            if(temp.size()>=3) return 1;
            auto it = lower_bound(temp.begin(), temp.end(), num);
            if(it == temp.end()){
                temp.push_back(num);
            }
            else *it = num;
        }
        return temp.size()>=3;
    }
};
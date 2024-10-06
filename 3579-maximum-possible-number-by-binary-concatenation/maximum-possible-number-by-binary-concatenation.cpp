class Solution {
public:
    string binary(int n){
        string ans;
        while(n){
            ans = (n%2 == 0 ? "0":"1")+ans;
            n/=2;
        } 
        return ans;
    }
    int fun(string &s){
        return stoi(s, 0, 2);
    }
    int maxGoodNumber(vector<int>& nums) {
        string a = binary(nums[0]);
        string b = binary(nums[1]);
        string c = binary(nums[2]);
        int maxi = 0;
        vector<string> s = {a,b,c};
        sort(s.begin(), s.end());
        do{
            string temp = s[0]+s[1]+s[2];
            int val = fun(temp);
            maxi = max(val, maxi);
        }
        while(next_permutation(s.begin(), s.end()));
        
        return maxi;
    }
};
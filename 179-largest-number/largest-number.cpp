class Solution {
public:
    static bool cmp(string a, string b){
        return a+b > b+a;
    }
    string largestNumber(vector<int>& nums) {
        vector<string>str;
        for(auto x: nums){
            str.push_back(to_string(x));
        }
        sort(str.begin(), str.end(), cmp);
        if(str[0] == "0") return "0";
        string ans = "";
        for(auto x : str){
            ans+=x;
        }
        return ans;
    }
};
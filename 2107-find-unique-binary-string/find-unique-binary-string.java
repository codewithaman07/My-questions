class Solution {
    public String findDifferentBinaryString(String[] nums) {
        StringBuilder ans = new StringBuilder();
        int n = nums.length;
        for(int i = 0; i<n; i++){
            char ch = nums[i].charAt(i);
            ans.append(ch == '0' ? '1' : '0');
        }
        return ans.toString();
    }
}

// class Solution {
// public:
//     string fun(int num){
//         string ans;
//         while(num>0){
//             ans = to_string(num%2)+ans;
//             num/=2;
//         }
//         return ans;
//     }
//     string findDifferentBinaryString(vector<string>& nums) {
//         set<int>st;
//         int n = nums.size();
//         for(int i = 0; i<n; i++){
//             st.insert(stoi(nums[i],0,2));
//         }
//         string temp = string(n,'1');
//         int limit = stoi(temp,0,2);
//         for(int i = 0; i<=limit; i++){
//             if(!st.count(i)){
//                 string x = fun(i);
//                 int y = x.size();
//                 string ans = string(n-y, '0');
//                 ans = ans+x;
//                 return ans;
//             }
//         }
//         return "";
//     }
// };
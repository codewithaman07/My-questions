class Solution {
public:
    char findKthBit(int n, int k) {
        string ans = "0";
        for(int i = 1; i<n && k>ans.length(); i++){
            ans+="1";
            for(int j = ans.size()-2; j>=0; j--){
                if(ans[j] == '1') ans+="0";
                else ans+="1";
            }
        }
        return ans[k-1];
    }
};
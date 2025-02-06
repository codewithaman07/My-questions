class Solution {
public:
    #define ll long long 
    long long appealSum(string s) {
        int n = s.size();
        ll ans = 0;
        for(char ch = 'a'; ch<='z'; ch++){
            int temp = 0;
            for(int i = 0; i<n; i++){
                if(s[i] == ch) temp = i+1;
                ans+=temp;
            }
        }
        return ans;
    }
};

        // int n = s.size();
        // ll ans = 0, curr = 0;
        // vector<int>mp(26,-1);
        // for(int i = 0; i<n; i++){
        //     curr+= (i-mp[s[i]-'a']);
        //     ans+= curr;
        //     mp[s[i]-'a'] = i;
        // }
        // return ans;
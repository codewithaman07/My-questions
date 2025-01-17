class Solution {
public:
    bool check(string &s, vector<int>&derived){
        int n = s.size();
        for(int i = 0; i<n-1; i++){
            int temp = ((s[i]-'0') ^ (s[i+1]-'0'));
            if(temp != derived[i]) return 0;
        }
        int temp = ((s[0]-'0') ^ (s[n-1]-'0'));
        if(temp != derived[n-1]) return 0;
        return 1;
    }
    bool doesValidArrayExist(vector<int>& derived) {
        int n = derived.size();
        string s0 = "0", s1 = "1";
        for(int i = 1; i<n; i++){
            if(derived[i-1] == 0){
                s0+= s0[i-1];
                s1+= s1[i-1];
            }
            else{
                s0 += s0[i-1] == '0' ? '1' : '0';
                s1 += s1[i-1] == '0' ? '1' : '0';
            }
        }
        cout<<s0<<endl;
        cout<<s1<<endl;
        return (check(s0, derived) || check(s1, derived));
    }
};
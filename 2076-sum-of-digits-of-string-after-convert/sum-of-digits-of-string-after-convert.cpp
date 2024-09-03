class Solution {
public:
    int getLucky(string s, int k) {
        string num;
        int n = s.size();
        for(int i = 0; i<n; i++){
            num+= to_string(s[i]-'a'+1);
        }
        for(int i = 0; i<k; i++){
            int temp = 0;
            for(int j = 0; j<num.size(); j++){
                temp+=(num[j]-'0');
            }
            num = to_string(temp);
        }
        return stoi(num);
    }
};
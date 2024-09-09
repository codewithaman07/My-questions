class Solution {
public:
    string convertDateToBinary(string date) {
        int n = date.size();
        string ans, temp;
        for(int i = 0; i<n; i++){
            if(date[i] != '-') temp+=date[i];
            else{
                if(ans.empty()){
                    bitset<32>bits(stoi(temp));
                    string x = bits.to_string();
                    x.erase(0,x.find_first_not_of('0'));
                    ans+=x;
                }
                else{
                    ans+="-";
                    bitset<32>bits(stoi(temp));
                    string x = bits.to_string();
                    x.erase(0,x.find_first_not_of('0'));
                    ans+=x;
                }
                temp = "";
            }
        }
        if(!temp.empty()){
            ans+="-";
            bitset<32>bits(stoi(temp));
            string x = bits.to_string();
            x.erase(0,x.find_first_not_of('0'));
            ans+=x;
        }
        return ans;
    }
};
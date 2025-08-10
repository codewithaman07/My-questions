class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string num = to_string(n);
        sort(num.begin(),num.end());
        do{
            int x = stoi(num);
            int bits = __builtin_popcount(x);
            if(bits == 1 && num[0] != '0') return 1;
        }
        while(next_permutation(num.begin(), num.end()));
        return 0;
    }
};
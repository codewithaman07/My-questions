class Solution {
public:
    bool isSet(int num , int pos) {return (num & (1<<pos));}
    void setbit(int &num, int pos) {(num |= (1<<pos));}
    void unset(int &num , int pos) {(num &= ~(1<<pos));}
    int minimizeXor(int num1, int num2) {
        int ans = num1, pos = 0;
        int csb = __builtin_popcount(num2);
        int sb = __builtin_popcount(ans);
        while(sb < csb){
            if(!isSet(ans, pos)){
                setbit(ans, pos);
                sb++;
            }
            pos++;
        }
        while(sb > csb){
            if(isSet(ans, pos)){
                unset(ans, pos);
                sb--;
            }
            pos++;
        }
        return ans;
    }
};
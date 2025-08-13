class DataStream {
public:
    // vector<int>data;
    int value, k, dataVals = 0;
    DataStream(int value, int k) {
        this->value = value;
        this->k = k;
    }
    
    bool consec(int num) {
        if(num == value) dataVals++;
        else dataVals = 0;
        if(dataVals>=k) return true;
        return false;
    }
};
// time complexity - O(N)
//N = no of times we encoured conse method
//Space complexity - O(1)
// arr -> 4, 4, 4, 3 
/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */
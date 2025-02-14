class ProductOfNumbers {
public:
    vector<int>arr;
    int n = 0;
    ProductOfNumbers() {
        arr.push_back(1);
    }
    
    void add(int num) {
        if(num == 0){
            n = 0;
            arr.clear();
            arr.push_back(1);
        }
        else{
            arr.push_back(arr[n]*num);
            n++;
        }
    }
    
    int getProduct(int k) {
        if(k>n) return 0;
        return arr[n]/arr[n-k];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
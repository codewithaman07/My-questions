class NumberContainers {
public:
    unordered_map<int,int>mp;
    unordered_map<int,set<int>>num;
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if(mp.count(index)){
            int prev = mp[index];
            num[prev].erase(index);
            if(num[prev].empty()) num.erase(prev);
        }
        mp[index] = number;
        num[number].insert(index);
    }
    
    int find(int number) {
        if(num.count(number)){
            return *num[number].begin();
        }
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
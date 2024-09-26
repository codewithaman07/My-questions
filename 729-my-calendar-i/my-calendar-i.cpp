class MyCalendar {
public:
    vector<pair<int,int>>arr;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        int n = arr.size();
        if(n == 0){
            arr.push_back({start,end});
            return 1;
        }
        for(auto p : arr){
            int prevStart = p.first;
            int prevEnd = p.second;
            if(prevStart<end && start<prevEnd) return 0;
        }
        arr.push_back({start,end});
        return 1;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
class MyCalendarTwo {
public:
    map<int,int>booking;
    MyCalendarTwo() {
        
    }
    
    bool book(int startTime, int endTime) {
        booking[startTime]++;
        booking[endTime]--;
        int totalBookings = 0;
        for(auto &[date, status] : booking){
            totalBookings+=status;
            if(totalBookings >= 3){
                booking[startTime]--;
                booking[endTime]++;
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(startTime,endTime);
 */
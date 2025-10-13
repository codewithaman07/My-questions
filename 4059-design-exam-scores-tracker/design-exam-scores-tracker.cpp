class ExamTracker {
public:
    #define ll long long
    map<ll,ll>mp;
    ll sum = 0;
    ExamTracker() {
        
    }
    
    void record(int time, int score) {
        sum+=score;
        mp[time]+=sum;
    }
    
    long long totalScore(int startTime, int endTime) {
        auto it = mp.upper_bound(endTime);
        if(it == mp.begin()) return 0;
        it--;
        if(it->first < startTime) return 0;
        ll ans = it->second;
        it = mp.lower_bound(startTime);
        if(it == mp.begin()) return ans;
        it--;
        return ans - it->second;
    }
};

/**
 * Your ExamTracker object will be instantiated and called as such:
 * ExamTracker* obj = new ExamTracker();
 * obj->record(time,score);
 * long long param_2 = obj->totalScore(startTime,endTime);
 */
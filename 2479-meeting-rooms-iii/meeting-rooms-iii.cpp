class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end(),
             [](const vector<int>& a, const vector<int>& b){ return a[0] < b[0]; });

        using ll = long long;
        // busy: (endTime, roomId)  — min-heap
        priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> busy;
        // free: roomId  — min-heap
        priority_queue<int, vector<int>, greater<int>> free;
        for (int i = 0; i < n; ++i) free.push(i);

        vector<int> cnt(n, 0);

        for (auto &mt : meetings) {
            ll start = mt[0], end = mt[1];
            ll dur   = end - start;

            // 1) release finished rooms
            while (!busy.empty() && busy.top().first <= start) {
                free.push(busy.top().second);
                busy.pop();
            }

            int room;
            ll newEnd;
            if (!free.empty()) {                 // 2) run on a free room
                room   = free.top(); free.pop();
                newEnd = start + dur;
            } else {                             // 3) delay until earliest room free
                auto [earliestEnd, r] = busy.top(); busy.pop();
                room   = r;
                newEnd = earliestEnd + dur;
                start  = earliestEnd;            // (not used later, kept for clarity)
            }

            busy.push({newEnd, room});
            ++cnt[room];
        }

        // 4) choose the room with max meetings
        int best = 0;
        for (int i = 1; i < n; ++i)
            if (cnt[i] > cnt[best]) best = i;

        return best;
    }
};

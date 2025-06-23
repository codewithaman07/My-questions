class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        // Use a map to handle arbitrary year ranges
        map<int,int> delta;
        for (auto& p : logs) {
            delta[p[0]] += 1;   // +1 at birth year
            delta[p[1]] -= 1;   // -1 at death year (exclusive)
        }
        int curr = 0, maxPop = 0, ansYear = INT_MAX;
        for (auto& [year, change] : delta) {
            curr += change;
            if (curr > maxPop) {
                maxPop = curr;
                ansYear = year;
            }
        }
        return ansYear;
    }
};

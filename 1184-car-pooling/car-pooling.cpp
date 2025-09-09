class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int farthestPoint = 0;
        for(auto trip : trips){
            farthestPoint = max(farthestPoint, trip[2]);
        }
        vector<int>carFreq(farthestPoint+2, 0);
        for(auto trip : trips){
            int start = trip[1];
            int end = trip[2];
            int people = trip[0];
            carFreq[start]+=people;
            carFreq[end]-=people;
        }
        int totalPeople = 0;
        for(int people : carFreq){
            totalPeople += people;
            if(totalPeople > capacity) return false;
        }
        return true;
    }
};
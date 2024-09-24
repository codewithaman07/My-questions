class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = speed.size();
        vector<pair<int,int>>temp;
        for(int i = 0; i<n; i++){
            temp.push_back({position[i], speed[i]});
        }
        sort(temp.begin(), temp.end(), greater<pair<int,int>>());
        stack<double>st;
        for(auto it : temp){
            double time = (double)(target-it.first)/it.second;
            if(st.empty() || time >st.top()) st.push(time);
        }
        return st.size();
    }
};
class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys,
                   vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        
        int n = status.size();
        vector<bool> used(n, false);        
        vector<bool> hasBox(n, false);      
        vector<bool> hasKey(n, false);      
        
        queue<int> q;
        
        for (int box : initialBoxes) {
            hasBox[box] = true;
            q.push(box);
        }
        int totalCandies = 0;
        while (!q.empty()) {
            int box = q.front();
            q.pop();
            
            if (!status[box] && !hasKey[box]) continue; 
            if (used[box]) continue;                    
            used[box] = true;
            totalCandies += candies[box];
            for (int key : keys[box]) {
                hasKey[key] = true;
                if (hasBox[key] && !used[key]) {
                    q.push(key);
                }
            }
            for (int newBox : containedBoxes[box]) {
                hasBox[newBox] = true;
                if (!used[newBox]) {
                    q.push(newBox);
                }
            }
        }  
        return totalCandies;
    }
};

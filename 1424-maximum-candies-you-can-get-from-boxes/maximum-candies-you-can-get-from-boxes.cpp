class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int n = status.size(), ans = 0;
        vector<int>used(n,0);
        vector<int>k(n,0);
        vector<int>boxes(n,0);
        queue<int>q;
        for(int i : initialBoxes){
            q.push(i);
            boxes[i] = 1;
        }
        while(!q.empty()){
            int box = q.front();
            q.pop();
            if(used[box]) continue;
            if(!k[box] && !status[box]) continue;
            used[box] = 1;
            ans+=candies[box];
            for(int x : keys[box]){
                k[x] = 1;
                if(!used[x] && boxes[x]) q.push(x); 
            }
            for(int x : containedBoxes[box]){
                boxes[x] = 1;
                if((k[x] || status[x]) && !used[x]) q.push(x);
            }
        }
        return ans;
    }
};
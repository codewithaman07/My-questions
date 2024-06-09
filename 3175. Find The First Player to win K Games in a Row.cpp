// Queue

class Solution {
public:
    int findWinningPlayer(vector<int>& skills, int k) {
        int n = skills.size();
        int maxi = INT_MIN;
        int idx = -1;
        for(int i = 0; i<n; i++){
            if(skills[i]>maxi){
                maxi = skills[i];
                idx = i;
            }
        }
        queue<int>q;
        for(int i = 0; i<n; i++){
            q.push(i);
        }
        int ans = q.front();
        q.pop();
        int won = 0;
        while(won<k){
            if(maxi == skills[ans]){
                return ans;
            }
            int next = q.front();
            q.pop();
            if(skills[ans]>skills[next]){
                q.push(next);
                won++;
            }
            else{
                q.push(ans);
                ans = next;
                won = 1;
            }
        }
        return ans;
    }
};
